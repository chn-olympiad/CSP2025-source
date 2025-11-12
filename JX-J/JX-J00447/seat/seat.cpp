#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],a1;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m-1;j++){
            if(a[j]<=a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
   /* for(int i=1;i<=n*m;i++){
        cout<<a[i]<<' ';
    }*/
    for(int i=1;i<=n*m;i++){
        if(a1==a[i]){
            a1=i;
            break;
        }
    }
   long long c,r;

   if(a1%n==0){
        c=a1/n;
   }else{
        c=a1/n+1;
   }

   if(c%2==0){
        r=n-(c*n-a1-1);
   }else{
        r=a1-(c-1)*n;
   }
    cout<<c<<" "<<r;
    return 0;
}
