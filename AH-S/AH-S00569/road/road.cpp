#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,m,k,c[15],a[15][10010],s[10010],ans;
struct node{
    int v,w;
}p;
struct le{
    int u,v,w;
}r[1000010];
vector<vector<node>> f,t;
bool cmp(le x,le y){
    return x.w<y.w;
}
void cs(){
    for(int i=1;i<=n;i++)s[i]=i;
}
int fin(int x){
    if(s[x]=x)return x;
    return s[x]=fin(s[x]);
}
bool hb(int c1,int c2){
    if(fin(c1)=fin(c2))return false;
    s[h1]=s[h2];
    return true;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
        p.v=r[i].u,p.w=r[i].w;
        f[r[i].u].push_back(p);
        p.v=u;
        f[r[i].v].push_back(p);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    sort(r+1,r+m+1,cmp);
    int k=0;
    cs();
    for(int i=1;i<=m;i++){
        if(hb(r[i].u,r[i].v)){
            ans+=r[i].w;
             k++;
        }
        if(k==n-1)break;
    }
    cout<<ans;
    return 0;
}
//**** *** ***!
