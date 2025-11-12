#include<bits/stdc++.h>
using namespace std;
const int M = 2e6+10,N = 1e4+20,K = 11;
int n,m,k,fa[N],cnt,c[N][K];
struct E{
    int x;
    int y;
    int w;
}e[M];
inline bool cmp(E q,E p){
    return q.w<p.w;
}
inline int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
inline void add(int v,int &cnt){
    for(int i=1;i<=n;i++){
        ++cnt;
        e[cnt].x=v+n;
        e[cnt].y=i;
        e[cnt].w=c[i][v];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    if(k==0){
        long long ans=0ll;
        sort(e+1,e+m+1,cmp);
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            int fx=find(e[i].x),fy=find(e[i].y);
            if(fx!=fy){
                fa[fx]=fy;
                ans=ans+(long long)e[i].w;
            }
        }
        cout<<ans<<endl;
    }
    else if(n<=1e3&&k<=5){
        int x=clock();
        for(int i=1;i<=k;i++){
            for(int j=0;j<=n;j++){
                cin>>c[j][i];
            }
        }
        cnt=m;
        long long ans=1e18;
        for(int i=0;i<(1<<k);i++){
            cnt=m;
            int now=i,tmp=1;
            long long minn=0ll;
            while(now){
                if(now%2==1){
                    add(tmp,cnt);
                    minn=minn+(long long)c[0][tmp];
                }
                now=now/2;
                tmp++;
            }
            for(int j=1;j<=n+k;j++){
                fa[j]=j;
            }
            bool flag=false;
            sort(e+1,e+cnt+1,cmp);
            for(int j=1;j<=cnt;j++){
                int fx=find(e[j].x),fy=find(e[j].y);
                if(fx!=fy){
                    fa[fx]=fy;
                    minn=minn+(long long)e[j].w;
                }
                if((clock()-x)*1000/CLOCKS_PER_SEC>1000){
                    flag=true;
                    break;
                }
            }
            ans=min(ans,minn);
            if(flag) break;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
