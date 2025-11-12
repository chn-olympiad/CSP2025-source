#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int n,m,w,s=0,x,y;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
        cin>>a[i];
   }
   w=a[1];
   sort(a+1,a+n*m+1,cmp);
   for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                s++;
                b[i][j]=a[s];
            }
        }else{
            for(int j=n;j>=1;j--){
                s++;
                b[i][j]=a[s];
            }
        }

   }
   for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==w){
                cout<<i<<" "<<j;
                return 0;
            }
        }
   }
   return 0;
}
