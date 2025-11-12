#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
using namespace std;

struct{char buf[1<<20],*l=buf,*r=l;
operator char(){return l==r&&(r=(l=buf)+fread(buf,1,1<<20,stdin),l==r)?-1:*l++;}
template<typename T>operator T(){
    T x=0;char f=0,c;
    do if((c=*this)=='-')f=1;while(c<'0'||c>'9');
    while(c>='0'&&c<='9')x=x*10+(c^48),c=*this;
    return f?-x:x;
}}in;void out(char c){putchar(c);}
template<typename T>void out(T x){
    static signed stk[39],tp;
    if(x<0)out('-'),x=-x;
    do stk[tp++]=x%10;while(x/=10);
    while(tp)putchar(stk[--tp]^48);
}template<typename T,typename...Args>
void out(T x,Args...args){out(x),out(args...);}

const int N = 10005,M = 10;
vector<array<int,3>> e,g[1<<M];
int c[M],a[M][N];
long long w[1<<M];
int n,m,K;

int fa[N+M];
int find(int x){return fa[x]?fa[x]=find(fa[x]):x;}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = in,m = in,K = in;
    e.resize(m);
    for(auto &[w,x,y]:e)
        x = in,y = in,w = in;
    for(int k=0;k<K;k++){
        c[k] = in;
        for(int j=1;j<=n;j++)
            a[k][j] = in;
    }
    sort(e.begin(),e.end());
    long long ans = 0;
    for(auto [w,x,y]:e){
        x = find(x),y = find(y);
        if(x==y)
            continue;
        ans += w;
        fa[x] = y;
        g[0].push_back({w,x,y});
    }

    for(int k=1;k<(1<<K);k++){
        memset(fa,0,sizeof(int)*(n+K+1));
        int j = __lg(k&-k);
        long long res = (w[k]=w[k^(1<<j)]+c[j]);
        e = g[k^(1<<j)];
        for(int i=1;i<=n;i++)
            e.push_back({a[j][i],i,n+1+j});
        sort(e.begin(),e.end());
        for(auto [w,x,y]:e){
            x = find(x),y = find(y);
            if(x==y)
                continue;
            res += w;
            fa[x] = y;
            g[k].push_back({w,x,y});
        }
        ans = min(ans,res);
    }

    out(ans);
}