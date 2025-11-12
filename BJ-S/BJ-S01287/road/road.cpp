#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int n2,n3;
int fa[11000];
struct g{
    int x,y;
    long long z;
}a[1000100];
int find1(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find1(fa[x]);
}
void union2(int x,int y){
    int fx=find1(x);
    int fy=find1(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
bool cmp(g a,g b){
    return a.z<b.z;

}
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    n2=n;
    n3=n+k;
    for(int i=1;i<=n+k+k+k;i++){
        fa[i]=i;
    }
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[i].x=u;
        a[i].y=v;
        a[i].z=w;
    }
    for(int i=1;i<=k;i++){
        int u;
        cin>>u;
        m++;
        n2++;
        int dx=n2;
        a[m].x=n2;
        n3++;
        a[m].y=n3;
        a[m].z=u;
        for(int j=1;j<=n;j++){

            cin>>u;
            m++;
            a[m].x=dx;
            a[m].y=j;
            a[m].z=u;
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        int f=0;
        for(int j=1;j<=n;j++){
            if(fa[j]==j) f++;
        }
        //cout<<f<<endl;
        if(f==1) break;

        if(find1(a[i].x)!=find1(a[i].y)){
            if(a[i].x>n&&a[i].y<=n&&find1(a[i].x)!=find1(a[i].x+k)) continue;
            if(a[i].y>n&&a[i].x<=n&&find1(a[i].y)!=find1(a[i].y+k)) continue;
            union2(a[i].x,a[i].y);
            ans+=a[i].z;
            //cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
        }
    }
    cout<<ans;
    return 0;
}
