#include<bits/stdc++.h>
using namespace std;
const int dd=114514;
int p[dd*2],k,n,m,ge;
long long ans;
struct Edge{
    int pre,to,w;
}e[2*dd];
struct Union{
    int s,fa[dd];
    void chu(int x){
        for(int i=1;i<=x;i++) fa[x]=0;
        s=x;
    }
    int sou(int a){
        return fa[a]=sou(fa[fa[a]]);
    }
    void sumup(int a,int b){
        if(fa[a]!=fa[b]) sumup(sou(a),sou(b));
        fa[a]=fa[sou(b)];
    }
}aa[12];
struct node{
    long long sum,dis;
    bool operator <(const node &x) const{
        return x.dis<dis;
    }
};
priority_queue<node,vector<node>,less<node> > q;
inline void add_edge(const int &x,const int &y,const int &z){
    e[k++].to=y;
    e[k].w=z;
    e[k].pre=p[x];
    p[x]=k;
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>m>>ge;
for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    add_edge(a,b,c);
    add_edge(b,a,c);
}

for(int i=1;i<=ge;i++){
    ans=0;
    int zhi,w;

}
return 0;
}
