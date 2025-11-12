#include<bits/stdc++.h>
using namespace std;
struct Na{
    long long x,y,z;
}l[2000010];
long long fa[10010],n,m,k,u,v,w,c[100],a[100][10010],sumfix,cnt;
long long sum;
bool vis[10010],fin[100];
long long cmp(Na a,Na b){
    return a.z<b.z;
}
long long find(long long x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void add(long long x,long long y){
    fa[x]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        l[i].x=u;
        l[i].y=v;
        l[i].z=w;
        cnt++;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cnt++;
            cin>>a[i][j];
            l[cnt].x=i;
            l[cnt].y=j;
            l[cnt].z=a[i][j];
        }
    }
    sort(l+1,l+1+cnt,cmp);
    sum=0;
    for(int i=1;i<=cnt;i++){
        if(find(l[i].x)!=find(l[i].y)){
            add(l[i].x,l[i].y);
            sum+=l[i].z;
        }
    }
    cout<<sum;
    return 0;
}
