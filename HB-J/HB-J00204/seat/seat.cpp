#include <iostream>
using namespace std;
int main(){
    int n,m,b=0;
    cin>>n>>m;
    int a[m*n],c[m*n];
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
        if(a[i]>b){
           b=a[i];
        }
        c[1]=b;
    }
    for(int i=1;i<=m*n;i++){
         int x=0;
        for(int j=1;j<=m*n;j++){
            if(a[j]>b&&a[j]<=c[i]){
               x=a[j];
         }
         c[i+1]=x;
    }
    }
    for(int i=1;i<=m*n;i++){
        if(a[1]==c[i]){
            if(i<n){
               cout<<1<<" "<<i;
               return 0;
            }
            if(i%n==0){
               cout<<i/n<<" ";
            }
            else{
                cout<<i/n+1<<" ";
            }
            if(i%(2*n)>n){
                cout<<n+1-i%(2*n);
            }
            else{
                 cout<<i%n;
            }

        }
     }

    return 0;
}
