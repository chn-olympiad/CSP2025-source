#include<bits/stdc++.h>
using namespace std;
int a[5000];int n;int m;
long long ans = 0;
//int p[100];
void dfs(int f,int s,int maxn,int sum)
{
    //cout << f << " " << s << " " << maxn <<" " << sum << endl;
    if(f>n||s>n)return;
    if(2*maxn<sum&&f == m)
    {
        ans++;
        //cout << "ans" << endl;
        //for(int i = 1;i<=f;i++)cout << p[i] << " ";
        //cout << endl;
        return;
    }
    //p[f] = a[s];
    dfs(f+1,s+1,max(maxn,a[s+1]),sum+a[s+1]);
    dfs(f,s+1,maxn,sum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(m = 3;m<=n;m++)
    {
        //cout << m << endl;
        dfs(0,0,0,0);
    }
    cout << ans%998244353;
    return 0;
}
