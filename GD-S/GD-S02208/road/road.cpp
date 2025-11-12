#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,flag=0; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') flag=1; c=getchar();}
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return flag ? ~(x-1) : x;
}

const int N=1e4+15,M=1e6+5,K=1145;
struct edge{
    int to,nxt,val,zhen;
}e[M<<2];
int n,m,k,u,v,w;
int c[15],usd[15];
int head[N],top;
struct node{
    int zhen,to,val;
}mn[N];
ll ans;
pair<int,int> dd[K][N];

void add(int u,int v,int w,int i=0){
    e[++top]={v,head[u],w,i};
    head[u]=top;
}

class set{
    public:
        void clear(){for(int i=0; i<N; i++) f[i]=i;}
        int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
        void merge(int x,int y){f[find(x)]=find(y);}
    private:
        int f[N];
}st;

void boruvka(){
    st.clear();
    int cnt=n;
    while(cnt>1){
        // printf("%d\n",cnt);
        for(int i=1; i<=n+k; i++) mn[i].val=1145141919;
        for(u=1; u<=n; u++){
            int x=st.find(u);
            for(int i=head[u]; i; i=e[i].nxt){
                v=e[i].to;
                // printf("%d -> %d\n",u,v);
                if(v>n && !usd[v-n]){
                    v-=n;
                    pair<int,int> a;
                    for(int i=1; i<=n; i++){
                        if(st.find(dd[v][i].second)!=x){
                            a=dd[v][i];
                            break;
                        }
                    }
                    int tval=e[i].val+c[v]+a.first;
                    // printf("--->%d %d\n",a.second,tval);
                    if(mn[u].val>tval)
                        mn[u]={v,a.second,tval};
                }else{
                    if(e[i].val<mn[u].val)
                        mn[u]={0,v,e[i].val};
                }
            }
        }
        // puts("-------");
        // for(int i=1; i<=n; i++) printf("%d ",mn[i].to); puts("");
        // puts("(****)");
        for(u=1; u<=n; u++)
            if(st.find(u)!=st.find(mn[u].to)){
                st.merge(u,mn[u].to);
                cnt--;
                ans+=mn[u].val;
                if(mn[u].zhen && !usd[mn[u].zhen]){
                    st.merge(u,mn[u].zhen+n);
                    st.merge(mn[u].to,mn[u].zhen+n);
                    usd[mn[u].zhen]=1;
                }
            }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    while(m--){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    for(int i=1; i<=k; i++){
        c[i]=read();
        u=n+i;
        for(v=1; v<=n; v++){
            w=read();
            add(u,v,w,i),add(v,u,w,i);
            dd[i][v]={w,v};
        }
        sort(dd[i]+1,dd[i]+n+1);
    }
    boruvka();
    printf("%lld\n",ans);
    return 0;
}
