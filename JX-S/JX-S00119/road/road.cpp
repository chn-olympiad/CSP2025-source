#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define i64 long long
#define ui64 unsigned long long
#define ui unsigned int
#define maxn 10000
using namespace std;
ui n,m,k;
struct E{
    ui w,v,u;
}s;
vector<E> e;
ui64 ans;
ui fa[maxn];
ui64 a[maxn][maxn],c[12];
ui found(ui a){
    if(fa[a]==a) return a;
    else{
        fa[a]=found(fa[a]);
        return fa[a];
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(ui i=1;i<=m;i++){
        cin>>s.u>>s.v>>s.w;
        e.push_back(s);
    }
    if(k==0){
    sort(e.begin(),e.end(),[](E a,E b){return a.w<b.w;});
    for(ui i=1;i<=n;i++) fa[i]=i;
    for(auto i:e){
        if(found(i.v)!=found(i.u)){fa[found(i.v)]=fa[found(i.u)],ans+=i.w;continue;}
        else continue;
    }
    cout<<ans;return 0;
    }
    if(k==1){
    sort(e.begin(),e.end(),[](E a,E b){return a.w<b.w;});
    for(ui i=1;i<=n;i++) fa[i]=i;
    for(auto i:e){
        if(found(i.v)!=found(i.u)){fa[found(i.v)]=fa[found(i.u)],ans+=i.w;continue;}
        else continue;
    }
    for(ui i=1;i<=k;i++){
        cin>>c[k];
        for(ui i=1;i<=n;i++){
            cin>>a[k][i];
        }
    }
    ui64 ans1=c[1];
    for(ui i=1;i<=n;i++){
        for(ui j=i+1;j<=n;j++){
            s.u=i,s.v=j,s.w=a[1][j]+a[1][i];
            e.push_back(s);
        }
    }
    sort(e.begin(),e.end(),[](E a,E b){return a.w<b.w;});
    for(ui i=1;i<=n;i++) fa[i]=i;
    for(auto i:e){
        if(found(i.v)!=found(i.u)){fa[found(i.v)]=fa[found(i.u)],ans1+=i.w;continue;}
        else continue;
    }
    cout<<min(ans1,ans);return 0;
    }
}
