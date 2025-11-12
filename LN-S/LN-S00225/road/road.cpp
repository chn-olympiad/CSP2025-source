#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,ans,oi[100005],v[100005],cnt,fa[100005],io,jll;
struct node{
    int x;
    int y;
    int z;
}a[1000005];
bool cmp(node x,node y){
    return x.z<y.z;
}
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    T=1;
    while(T--){
        cin>>n>>m>>k;
        cnt=0;
        memset(v,0,sizeof(0));
        for(int i=1;i<=n;i++)
            fa[i]=i;
        v[1]=1;
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        for(int i=1;i<=k;i++){
            cin>>io;
            for(int j=1;j<=n;j++){
                cin>>jll;
                a[++m].x=i;
                a[m].y=j;
                a[m].z=jll;
            }
        }
        //cout<<666;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(find(a[i].x)==find(a[i].y))continue;
            fa[a[i].x]=a[i].y;
                //cout<<a[i].x<<' '<<a[i].y<<' '<<find(a[i].x)<<' '<<find(a[i].y)<<endl;
            cnt+=a[i].z;
        }
        cout<<cnt<<endl;
    }
}
/*
5 7 1
1 2 8
2 3 7
3 4 4
4 5 10
3 1 9
4 1 6
2 4 5
0 35 456 2 345 567
*/


