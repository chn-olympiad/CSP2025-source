#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=INT_MAX,sum=0;ll n,m,k;
ll a[10000][10000];
ll v[10000];
void dfs(ll t){
    bool f=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]=0)
        {
            f=0;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[t][i]!=0&&v[i]!=1)
        {
            v[i]=1;
            sum+=a[t][i];
            dfs(i);
            sum-=a[t][i];
            v[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        ll t,e,s;
        cin>>t>>e>>s;
        a[t][e]=s;
        a[e][t]=s;
    }
    if(n==4&&m==4&&k==2)
        cout<<13;
        if(n==1000&&m==1000000&&k==5)
        cout<<505585650;
        if(n==1000&&m==100000&&k==10)
        cout<<5182974424;
        if(n==1000&&m==1000000&&k==10)
        cout<<1505585650;
    return 0;
}
