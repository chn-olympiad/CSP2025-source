#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[10000];
long long bao=0;
void dfs(int x,int y)
{
    if(y-x+1<3)return ;
    int ans=0;
    int maxn=-1145141919;
    for(int i=x;i<=y;i++)
    {
        ans+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(ans<=maxn*2)return ;
    bao=(bao+1)%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        dfs(i,j);
    }
    cout<<bao;
    return 0;
}
