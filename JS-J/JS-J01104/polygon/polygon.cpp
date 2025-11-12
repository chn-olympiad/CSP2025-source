/*
CSP-J 2025 T4
Author: DFLJ
Solution:
24pts is permutaion 09:50
20pts is for YangHui 11:40
I think I can get 24pts.
If I am lucky,I can get 44pts.
So my score is 100+100+100+44=344pts.
That is very nice,
but emmmm.
Best Wishes.
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
bool f[5005];
int c[5002][5002];
int n;
long long ans=0;
bool chk(int sum,int las,int k)
{
    if(k<3) return 0;
    if(sum>a[las]*2) return 1;
    return 0;
}
void dfs(int step,int k,int sum,int las)
{
    if(step>n)
    {
        if(chk(sum,las,k)) ans++;
        return ;
    }
    dfs(step+1,k+1,sum+a[step],step);
    dfs(step+1,k,sum,las);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=10)
    {
        dfs(1,0,0,0);
    }
    else
    {
        if(a[n]==1)
        {
            c[1][1]=1;
            c[2][1]=c[2][2]=1;
            for(int i=3; i<=n; i++)
            {
                for(int j=1; j<=i; j++)
                {
                    c[i][j]=c[i-1][j-1]+c[i-1][j];
                    c[i][j]%=mod;
                }
            }
            for(int i=3; i<=n; i++)
            {
                ans+=c[n][i];
            }
        }
        else
        {
            cout<<114514;
        }
    }
    cout<<ans%mod;
    return 0;
}