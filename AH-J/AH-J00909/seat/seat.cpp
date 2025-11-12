#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    int k;
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
           k=n*m-i+1;
        }
    }
    if(k%n==0){
      if((k/n)%2==0){
         printf("%d 1",k/n);
      }else{
         printf("%d 1",k/n);
      }
    }else{
      int t=k%n;
      if((k/n)%2==0){
         printf("%d %d",k/n+1,t);
      }else{
         printf("%d %d",k/n+1,n-t+1);
      }
    }
    return 0;
}
