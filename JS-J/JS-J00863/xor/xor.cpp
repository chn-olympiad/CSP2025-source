#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;

int ans;
int n,k;
int a[N];
int vis[N];
int solve(int st,int ed)
{
    int res = 0;
    int cnt = 0;
    for(int i = st;i <= ed;i++)
    {
        res = res | a[i];
        if(res == k)
        {
            cnt++;
            res = 0;
        }
    }
    return cnt;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        int res = a[i] | k;
        if(a[i] > k)vis[i] = 2;
        if(res > k)vis[i] = 2;
        if(a[i] == k)
        {
            ans++;
            vis[i] = 2;
        }
    }
    if(k <= 1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == k)ans++;
        }
        cout << ans <<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int j = 1;
    int res;
    for(int i = 1;i <= n;i++)
    {
        res = 0;
 //       cout <<endl<<endl;
  //      cout << i <<endl;
        if(vis[i] == 2)
        {
            res = 0;
            j = i + 1;
        }
        else if(vis[i + 1] == 2 || i == n)
        {
            res = solve(j,i);
   //         cout <<"getone "<< res <<"    " <<j<<" "<<i<<endl;
        }
   //     cout <<"nowans: "<<ans<<endl;
        ans += res;
    }
    cout << ans <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
