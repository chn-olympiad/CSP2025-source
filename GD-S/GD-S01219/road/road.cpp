#include<iostream>
#include<algorithm>
#define ll long long
using std::cin;
using std::cout;
using std::min;
using std::sort;
const int N=2e4+10,EDGE=2.5e6+10;
struct Edge{ll u,v,w;}E[EDGE],all[EDGE];
inline bool cmp(Edge&x,Edge&y){return x.w<y.w;}
ll a[15][N],zero[15],c[15],fa[N];
inline ll getfa(ll x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m,k;
    ll i,j,ii,len,answer=9223372036854775807ll,ans;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i)
        cin>>E[i].u>>E[i].v>>E[i].w;
    for(i=1;i<=k;++i){
        cin>>c[i];
        for(j=1;j<=n;++j){
            cin>>a[i][j];
            if(!a[i][j])
                zero[i]=j;
        }
    }
    for(i=0;i<1<<k;++i){
        len=m,ans=0;
        for(j=1;j<=m;++j)
            all[j]=E[j];
        for(j=1;j<=k;++j)
            if(i<<1>>j&1)
                for(ii=1,ans+=c[j];ii<=n;++ii)
                    all[++len]={zero[j],ii,a[j][ii]};
        sort(all+1,all+1+len,cmp);
        for(j=1;j<=n;++j)
            fa[j]=j;
        for(j=ii=1;ii<n&&j<=len;++j)
            if(getfa(all[j].u)!=getfa(all[j].v))
                ans+=all[j].w,++ii,fa[getfa(all[j].u)]=getfa(all[j].v);
        if(ii>=n)
        	answer=min(answer,ans);
    }
    cout<<answer;
    return 0;
}
