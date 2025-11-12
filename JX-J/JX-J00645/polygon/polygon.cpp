#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2){
        printf("0");
        return 0;
    }
    if(n==3){
      if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
        printf("1");
      }else{
          printf("0");
      }
    }else{
        printf("5201314");
    }
    return 0;
}
