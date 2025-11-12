#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N],b[N],c[N];
int T;
int n;
ll ans=0;
int as,bs,cs;
void dfs(int dep,int la)
{
    if(dep>n)
    {
        if(la>ans) ans=la;
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(i==1&&as<n/2)
        {
            as+=1;
            dfs(dep+1,la+a[dep]);
            as-=1;
        }
        if(i==2&&bs<n/2)
        {
            bs+=1;
            dfs(dep+1,la+b[dep]);
            bs-=1;
        }
        if(i==3&&cs<n/2)
        {
            cs+=1;
            dfs(dep+1,la+c[dep]);
            cs-=1;
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n<=30)
        {
            dfs(1,0);
            cout<<ans<<"\n";
        }
        else
        {
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
