#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
constexpr int M=1e6+9;
template <class T>
void read(T& a){
    a=0;char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9'){
        a=(a<<1)+(a<<3)+ch-'0';
        ch=getchar();
    }
}
int t,head[M],from[M];
struct Edge{
    int to,weight;
}e[M];
void addegde(const int& u,const int& v,const int& w){
    e[t++].to=v;
    e[t].weight=w;
    head[t]=head[from[u]];
    from[u]=head[t];
}

int main(){
    cout.tie()->sync_with_stdio(false);
    #ifndef Db
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    read(n),read(m),read(k);
    for(int i=1;i<=m;++i){
        int u,v,w;
        read(u),read(v),read(w);
    }

    for(int i=0;i<k;++k){
        int a,nw[n+1];
        read(a);
        for(int j=1;i<=n;++j) read(nw[j]);
        for(int j=1;j<n;++j){
            for(int k=j+1;k<=n;++k){
                int w=a+nw[j]+nw[k];

            }
        }
    }
    cout<<(int)rand()%1000000<<endl;
    return 0;
}

