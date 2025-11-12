#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
namespace stdio_promax{
	inline void read(int& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void read(ll& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void write(int x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
	inline void write(ll x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
}
using namespace stdio_promax;
const int N=1e4+10,M=1e6+1e5+10,K=20;
const ll inf=1e15;
int n,m,k,head[N+K],nxt[M*2],to[M*2],w[M*2],E=0,c[K],dis[N+K];
bitset<K>b;
bitset<N+K>book;
ll ans=inf;
inline void add(int u,int v,int weight){
    ++E;
    nxt[E]=head[u];
    head[u]=E;
    to[E]=v;
    w[E]=weight;
}
void init(){
    book.reset();
    for(int i=1;i<=n+k;i++){
        dis[i]=INT_MAX;
    }
}
struct node{
    int id,dis;
    bool operator<(const node tw)const{
        return dis>tw.dis;
    }
};
void prim(){
    ll ret=0;
    int num=n;
    for(int i=1;i<=k;i++){
        if(b[i]){
            ret+=c[i];
            num++;
        }
    }
    init();
    int now=1;
    book[1]=1;
    priority_queue<node>q;
    for(int i=1;i<num;i++){
        for(int j=head[now];j;j=nxt[j]){
            if(!book[to[j]]&&(to[j]<=n||(to[j]>n&&b[to[j]-n]))){
                if(dis[to[j]]>w[j]){
                    q.push({to[j],w[j]});
                    dis[to[j]]=w[j];
                }
            }
        }
        now=q.top().id;
        int ds=q.top().dis;
        q.pop();
        while(book[now]){
            now=q.top().id;
            ds=q.top().dis;
            q.pop();
        }
        book[now]=1;
        ret+=ds;
        if(ret>=ans)return;
    }
    ans=ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n);read(m);read(k);
    int u,v,w;
    for(int i=1;i<=m;i++){
        read(u);read(v);read(w);
        add(u,v,w);add(v,u,w);
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        int a;
        for(int j=1;j<=n;j++){
            read(a);
            add(j,n+i,a);add(n+i,j,a);
        }
    }
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<k;j++){
            b[j+1]=(i>>j)&1;
        }
        prim();
    }
    write(ans);
    putchar('\n');
	return 0;
}
