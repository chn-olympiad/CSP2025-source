#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,k,u,v,w,ans,a[1005][100005],c[1005],nn,cnt,fa[10025],maxx[1025][1005],bj[1005];
struct node{
    int u,v,w;
    bool operator < (node p){
        return w<=p.w;
    }
}cn[1000005];
inline int find(int u){
    // cerr<<u<<'\n';
    if(fa[u]==u){
        return u;
    }else{
        fa[u]=find(fa[u]);
        return fa[u];
    }
}
signed main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m>>k;
//	n=read(),m=read(),k=read();
//    cerr<<n<<" "<<m<<" "<<k<<'\n';
    for(int i(0);i<=10021;++i)fa[i]=i;
    for(int i(1);i<=m;++i){
        cin>>u>>v>>w;
//		u=read(),v=read(),w=read();
        cn[++cnt]={u,v,w};
    }
    for(int i(1);i<=k;++i){
    	cin>>c[i];
//    	c[i]=read();
        for(int j(1);j<=n;++j){
//        	a[i][j]=read();
            cin>>a[i][j];
        }
    }
    for(int i(1);i<=n;++i){
        for(int j(1);j<=k;++j){
            maxx[i][j]=a[j][i];
//            cout<<i<<" "<<j<<" "<<maxx[i][j]<<'\n';
        }
    }
    sort(cn+1,cn+1+cnt);
    for(int i(1);i<=cnt;++i){
        int x=find(cn[i].u),y=find(cn[i].v);
        if(x==y)continue;
        fa[x]=y;
        find(x);
        int anss=LONG_LONG_MAX,t=0;
        for(int j(1);j<=k;++j){
            if(maxx[x][j]+(!bj[j])*c[j]+maxx[y][j]<anss){
                t=j;
                anss=maxx[x][j]+(!bj[j])*c[j]+maxx[y][j];
            }
        }
        if(anss<=cn[i].w){
            bj[t]=1;
            ans+=anss;
//            cout<<cn[i].u<<" "<<cn[i].v<<" "<<ans<<" "<<anss<<" "<<t<<" R\n"; 
        }else{
            ans+=cn[i].w;
//            cout<<x<<" "<<y<<" "<<maxx[x][1]<<" "<<maxx[y][1]<<" "<<cn[i].u<<" "<<cn[i].v<<" "<<ans<<" "<<anss<<" "<<cn[i].w<<" B\n"; 
        }
//        cerr<<ans<<'\n';
        for(int j(1);j<=k;++j){
            maxx[y][j]=min(maxx[y][j],maxx[x][j]);
        }
    }
    cout<<(unsigned long long)ans;
    return 0;
}
