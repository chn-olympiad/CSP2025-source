#include<bits/stdc++.h>
#define byGyf return
using namespace std;
int n,a[5005]={0};
int cnt=0;
int t=0;
void dfs(int x,int st,int sum,int maxx)
{
    t++;
    if(st>=3&&sum>maxx*2)
    {
        //cout<<st<<" "<<sum<<endl;
        cnt=(cnt+1)%998244353;
    }
    for(int i=x+1;i<=n;i++)
    {
        dfs(i,st+1,sum+a[i],max(maxx,a[i]));
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,1,a[i],a[i]);
    }
    cout/*<<t<<" "*/<<cnt%998244353;
    byGyf 0;
}
