#include<bits/stdc++.h>
using namespace std;
int t,n,mid;
int s[100100][5];
int l[5]={0};
int sum=0,ans=0;
void dfs(int k)
{
  //  cout << n << endl;

    for(int i=1 ; i<=3 ; i++)
    {
        //cout << k << endl;
        if(l[i] < mid)
        {
            //cout <<"a"<<endl;
            l[i]++;
            sum+=s[k][i];
            if(k == n)
            {
                ans=max(ans,sum);
            }
            if(k<n)
                dfs(k+1);
            sum-=s[k][i];
            l[i]--;
        }
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i=0 ; i<t ; i++)
    {
        cin >> n;
        for(int i=1 ; i<=n ; i++)
        {
            cin >> s[i][1]>> s[i][2] >> s[i][3];
        }
        sum=0;
        l[1]=0;
        l[2]=0;
        l[3]=0;
        mid=n/2;
        dfs(1);
        cout << ans << endl;
        ans=0;
    }

    return 0;
}
