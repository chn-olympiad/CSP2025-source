#include"bits/stdc++.h"
using namespace std;

int n,m,a,c,r;
int arr[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

   scanf("%d""%d",&n,&m);
   for(int i=0;i<n*m;i++){
        scanf("%d",&arr[i]);
   }
   a=arr[0];
   sort(arr,arr+n*m-1);
   for(int i=1;i<=n*m;i++){
        if(arr[i-1]==a){
            if(i%n==0){
                c=i/n;
                if(c%2==1){
                  r=n;
                }else{
                  r=1;
                }
            }else{
                c=i/n +1;
                if(c%2==1){
                  r=i%n;
                }else{
                  r=n-(i%n);
                }
            }

            break;
        }
   }
    printf("%d""%d",c,r);
    return 0;
}
