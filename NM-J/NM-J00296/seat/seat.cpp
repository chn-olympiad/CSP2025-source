#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int b[1000000];
bool mysort(int x,int y){
    if(x>y){
        return true;
    }
    else return false;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int m,n,w=0,u;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(i==1&&j==1){
                u=a[i][j];
            }
        }
   }
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[w]=a[i][j];
            w++;
        }
   }
   sort(b,b+w,mysort);
   w=0;
   for(int i=1;i<=m;i++){
        if(i%2!=0){
           for(int j=1;j<=n;j++){
                a[i][j]=b[w];
                w++;
                if(b[w-1]==u){
                    cout<<i<<" "<<j;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                a[i][j]=b[w];
                w++;
                if(b[w-1]==u){
                    cout<<i<<" "<<j;
                }
            }
        }
   }
   return 0;
}

