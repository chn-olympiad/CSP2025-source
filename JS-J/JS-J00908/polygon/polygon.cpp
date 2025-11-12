#include <bits/stdc++.h>

using namespace std;
int a[5002];
long long c[5002][5002];
int n;
long long num;
void dfs(int x,long long sum,int maxx)
{
    if(x>n)
    {
        if(sum>maxx*2)
        {
            num++;
            num%=998244353;
        }
        return ;
    }
    dfs(x+1,sum+a[x],a[x]);
    dfs(x+1,sum,maxx);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            d=1;
        }
    }
    if(d==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        }
        for(int i=3;i<=n;i++)
        {
            num=num+c[n+1][i+1]%998244353;
            num%=998244353;
        }
        cout<<num;
        return 0;
    }
    sort(a+1,a+1+n);
    dfs(1,0,0);
    cout<<num;
    return 0;
}
