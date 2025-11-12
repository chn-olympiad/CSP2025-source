#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        int s=0;
        for(int i=1;i<=m;i++){
          s+=v;
        }
    printf("%d",&s);
    }
    return 0;
}
