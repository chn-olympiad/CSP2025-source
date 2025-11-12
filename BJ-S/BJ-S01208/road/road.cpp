#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a,b,x,c,tmp;

int onion[10007];

int read(){
    char t;
    int s=0;
    t = getchar_unlocked();
    while(isdigit(t)){
        s = s*10+t-48;
        t = getchar_unlocked();
    }
    return s;
}

inline void Oinit(){
    for(int i = 1;i <= n;++i)onion[i] = i;
}

inline int Ofind(int z){
    if(onion[z]==z)return z;
    else return onion[z] = Ofind(onion[z]);
}

inline void Omerge(int z,int y){
    onion[Ofind(z)] = Ofind(y);
}

struct edge{
    int u,v,w;
};
vector<edge> graph,graph2;
vector<int> d[10007];

inline void input(){
    n=read();
    m=read();
    k=read();
    for(int i = 0;i < m;++i){
        a=read();
        b=read();
        x=read();
        graph.push_back(edge{a,b,x});
    }
    for(int j = 0;j < k;++j){
        for(int i = 0;i <= n;++i){
            tmp=read();
            d[j].push_back(tmp);
        }
    }
}
inline bool cmp(edge a,edge b){
    return a.w < b.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0);
    input();
    unsigned int ans = 18446744073709551615ull;
    for(int i = 0;i < 1<<k;++i){
        if(i)graph.clear();
        int it = i,md=0,f=1;
        unsigned int anss=0;
        while(it){
            if(it&1){
                anss += d[md][0];
                if(anss >= ans){f=0;break;}
                for(a = 1;a <= n;++a){
                    for(b = 1+a;b <= n;++b){
                        graph.push_back(edge{a,b,d[md][a]+d[md][b]});
                    }
                }
            }
            it >>= 1;
            ++md;
        }
        if(!f)continue;
        if(i){
            graph.clear();
            for(int i = 0;i < graph2.size();++i)graph.push_back(graph2[i]);
        }
        Oinit();
        if(!f)continue;
        sort(graph.begin(),graph.end(),cmp);
        int choose=0;
        for(int j = 0;choose < n-1;++j){
            if(Ofind(graph[j].u)!=Ofind(graph[j].v)){//如果不在一起
                anss += graph[j].w;
                if(anss >= ans){f=0;break;}
                Omerge(graph[j].u,graph[j].v);
                if(!i){
                    graph2.push_back(edge{graph[j].u,graph[j].v,graph[j].w});
                }
                ++choose;
            }
        }
        if(!f)continue;
        /*for(b = 0;b < graph2.size();++b){
            cout << graph2[b].u << ' ' << graph2[b].v << ' ' << graph2[b].w << endl;
        }*/
        ans = min(ans,anss);
    }
    cout << ans;
    return 0;
}
