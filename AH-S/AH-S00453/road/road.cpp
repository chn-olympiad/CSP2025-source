#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull cnt=0;
int n,m,k;
int fa[10005],b[10005];
int get(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=get(fa[x]);
    }
}void merge(int x,int y,int k){
    int dx=get(x);
    int dy=get(y);
    if(dx!=dy){
        cnt=cnt+k;
        fa[dy]=dx;
    }
}
struct node{
    int i,j,k;
}a[1000005];
int l=1;
void init(){
    for(int i=1;i<=10000;i++){
        fa[i]=i;
    }
}
bool cmp(node a,node b){
    return a.k<b.k;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[l]={u,v,w};
        l++;
    }int temp;
    for(int i=1;i<=k;i++){
        cin>>temp;
        temp=0;
        for(int j=1;j<=n;j++){
            cin>>b[j];
            if(b[j]==0){
                temp=j;
            }
        }for(int j=1;j<=n;j++){
            a[l]={temp,j,b[j]};
            l++;
        }
    }sort(a+1,a+l,cmp);
    for(int i=1;i<l;i++){
        merge(a[i].i,a[i].j,a[i].k);
    }cout<<cnt;
    return 0;
}
