#include<bits/stdc++.h>
using namespace std;
int n,m,k,num;
int a[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int x,y,z;
    for(int i=1;i<=m;i++){
        if(i==1||i==2){
           num+=z;
        }
        scanf("%d%d%d",&x,&y,&z);
    }
    int s;
    for(int i=1;i<=2;i++){
        for(int i=1;i<=n+1;i++){
           scanf("%d",&s);
        }
    }
    printf("%d",num);
    return 0;
}
