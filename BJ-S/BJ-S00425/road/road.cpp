#include<bits/stdc++.h>
using namespace std;
int n,m,nm,k,ans;
struct xxs{
    int u,v,w;
}a[10000005];
int c[15],ww;
long long sum;
int f[10030];
bool cmp(xxs aa,xxs bb){
    return aa.w<bb.w;
}
int find(int x){
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    nm=m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ww;
            a[++nm].u=j;
            a[nm].v=n+i;
            a[nm].w=ww;
        }
    }
    ans=n+k;
    for(int i=1;i<=n+k;i++) f[i]=i;
    sort(a+1,a+nm+1,cmp);
    for(int i=1;i<=nm;i++){
        int x=find(a[i].u),y=find(a[i].v);
        if(x!=y){
            ans--;
            f[x]=y;
            sum+=a[i].w*1ll;
        }
        if(ans==1) break;
    }
    cout<<sum<<'\n';
    return 0;
}