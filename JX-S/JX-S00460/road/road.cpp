#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=1e9+7;
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    return x*f;
} 
void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m,k;
int fa[N];
int findx(int x){return x==fa[x]?x:fa[x]=findx(fa[x]);}
struct node
{
    int x,y,w;
};
vector<node>g;
bool cmp(node a,node b){return a.w<b.w;}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        g.push_back({a,b,c});
    }
    sort(g.begin(),g.end(),cmp);
    int ans=0;
    for(auto v:g)
    {
        int a=v.x,b=v.y,c=v.w;
        if(findx(a)==findx(b))continue;
        if(findx(a)!=findx(b))
        {
            ans+=v.w;
            if(fa[b]!=b)fa[a]=findx(fa[b]);
            else fa[b]=findx(fa[a]);
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    solve();
    return 0;
}