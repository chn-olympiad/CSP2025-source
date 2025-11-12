#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
void read(int &x){
    x=0;
    bool neg=false;
    char ch=getchar();
    while((ch>'9')||(ch<'0')){
        if(ch=='-') neg=true;
        ch=getchar();
    }
    while((ch<='9')&&(ch>='0')){
        x=x*10+(int)(ch-'0');
        ch=getchar();
    }
    if(neg) x=-x;
}
int N,M,K;
struct edge{
    int u,v,w;
    bool operator < (const edge &e2) const{
        return w<e2.w;
    }
};
vector<edge>E[3];
int fa[maxn];
void inti(){
    for(int i=1;i<=N+K;i++) fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
long long krue(int n,vector<edge>&vec1,vector<edge>&vec2){
    vec2.clear();
    int cnt=0;
    long long res=0;
    sort(vec1.begin(),vec1.end());
    for(auto arc:vec1){
        if(find(arc.u)==find(arc.v)) continue;
        res+=(long long)arc.w;
        vec2.push_back(arc);
        fa[find(arc.u)]=find(arc.v);
        cnt++;
        if(cnt==n-1) break;
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(N),read(M),read(K);
    for(int i=1;i<=M;i++){
        int u,v,w;
        read(u),read(v),read(w);
        E[0].push_back({u,v,w});
    }
    inti();
    long long pre=krue(N,E[0],E[1]),res;
    E[0]=E[1];
    int k=0;
    for(int i=1;i<=K;i++){
        int a,c;
        inti();
        read(c);
        E[2]=E[0];
        for(int j=1;j<=N;j++){
            read(a);
            E[0].push_back({N+i,j,a});
        }
        res=(long long)c+(long long)krue(N+k+1,E[0],E[1]);
        if(res>=pre){
            E[0]=E[2];
            continue;
        }
        k++;
        pre=res;
        E[0]=E[1];
    }
    printf("%lld",pre);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
