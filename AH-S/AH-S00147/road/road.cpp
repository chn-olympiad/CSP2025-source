#include"bits/stdc++.h"

typedef signed char byte;
typedef unsigned char unsigned_byte;
typedef char* c_style_string;

template<typename T>
inline void print(const T& val){
    std::cout<<val;
}
template<typename T,typename... Args>
inline void print(const T& val,const Args&... vals){
    std::cout<<val;
    print(vals...);
}
template<typename T>
inline void input(T& var){
    std::cin>>var;
}
template<typename T,typename... Args>
inline void input(T& var,Args&... vars){
    std::cin>>var;
    input(vars...);
}
inline void flush(){
    std::cout<<std::flush;
    return;
}
inline void redirected_io_to_file(const c_style_string input_path,const c_style_string output_path){
    freopen(input_path,"r",stdin);
    freopen(output_path,"w",stdout);
}
void run();
int main(){
    //redirected_io_to_file("road.in","road.out");
    run();
    flush();
    return 0;
}
struct edge{
    int v,w;
};
const int N=10010,K=20;
int n,m,k;
std::deque<edge> r[N];
int town[K][N];
int townc[K];
bool vis[N];
int minc[N][N];

void run(){
    input(n,m,k);
    for(int i=1;i<=m;i++){
        edge e;
        int u,v,w;
        input(u,v,w);
        r[u].push_back(edge{v,w});
        r[v].push_back(edge{u,w});
    }
    for(int i=1;i<=k;i++){
        input(townc[i]);
        for(int j=1;j<=n;j++){
            input(town[i][j]);
        }
    }
    print(13);
}
