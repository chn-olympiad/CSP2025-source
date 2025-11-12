#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    int j,k,s=0;
    int x=1,y=1;
    int a[107];
    cin>>m>>n;
    for(int i=0;i<n*m;i++){
         cin>>a[i];
}
     j=a[0];
     for(int i=0;i<n*m;i++){
         if(a[i]>a[s]){
         swap(a[i],a[s]);
         s=i;
    }
        }


   for(int i=0;i<n*m;i++){
        if(j==a[i]){
        k=i;
    }

}
      for(int i=0;i<k;i++){
            if(k>0){
            y++;
            if(y==n+1){
               y--;
               x++;
               k-=n;
               if(k>0){
               for(int l=0;l<k;l++){
                  y--;
                  if(y==0){
                    y++;
                    x++;
                    k-=n;
                    continue;
                  }
               }
              }
            }
      }
      }
      cout<<x<<' '<<y;


    return 0;
}


