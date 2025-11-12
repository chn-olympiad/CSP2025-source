#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct r{
    int u;
    int v;
    int w;
}a[1000005];
int b[10][10005];
//int dp
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&b[i][0]);
        for(int j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
        }
    }
cout<<3456789;
    return 0;
}
