#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
long long ans,anss;
int m,cnta,cntb,cntc;
void dfs(int x)
{
    if(cnta>m||cntb>m||cntc>m)
    {
        return;
    }
    if(x==n+1)
    {
        anss=max(anss,ans);
        return;
    }
    ans+=a[x];
    cnta++;
    x++;
    dfs(x);
    x--;
    ans-=a[x];
    cnta--;
    ans+=b[x];
    cntb++;
    x++;
    dfs(x);
    x--;
    ans-=b[x];
    cntb--;
    ans+=c[x];
    cntc++;
    x++;
    dfs(x);
    x--;
    ans-=c[x];
    cntc--;
}
int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        anss=0;
        ans=0;
        m=n/2;
        cnta=0;
        cntb=0;
        cntc=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(1);
        cout<<anss<<endl;
    }
    return 0;
}
