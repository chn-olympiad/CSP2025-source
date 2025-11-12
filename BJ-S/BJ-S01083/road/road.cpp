#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5;
struct tree{
    int u,v,w;
}a[N];
int p[M];
bool cmp(tree x,tree y){
    return x.w<y.w;
}
int find(int x){
    while(p[x]!=x){
        x=p[x];
    }
    return x;
}
bool Same_parent(int x,int y){
    return find(x)==find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    int sum=0;
    for(int i=1;i<=m;i++){
        if(!Same_parent(a[i].u,a[i].v)){
            p[find(a[i].v)]=find(a[i].u);
            sum+=a[i].w;
        }
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
