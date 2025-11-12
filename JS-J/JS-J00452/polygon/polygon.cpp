#include"bits/stdc++.h"
using namespace std;

int n;
int arr[5010];
int leng[5010];
long long k;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

   scanf("%d",&n);
   for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
   }
sort(arr,arr+n-1);
for(int i=0;i<n;i++){
        leng[i]=leng[i-1]+arr[i];
   }
   for(int z =3;z<=n;z++){
       for(int i =z;i<=n;i++){
            if(arr[z]<leng[z-1]){
                k=(k+z)%988;
                k = k%244;
                k= k%353;
            }
       }
   }
   printf("%d",k);

    return 0;
}
