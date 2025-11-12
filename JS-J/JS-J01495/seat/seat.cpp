#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b=1,q,w;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin.tie(0);
   cout.tie(0);
   ios::sync_with_stdio(false);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
    cin>>a[i];
   }
   for(int i=1;i<=n*m-1;i++){
    for(int j=1+i;j<=n*m;j++){
        if(a[i]<a[j]){
                if(i==b){
                    b=j;
                }
                else if(j==b){
                    b=i;
                }
            swap(a[i],a[j]);
        }
    }
   }
   q=b/n;
   w=b%n;
   if(w==0){
        if(q%2==0){
            cout<<q<<" "<<1;
        }
        else cout<<q<<" "<<m;
   }
   if(w!=0){
        if((q+1)%2==0){
            cout<<q+1<<" "<<m-w+1;
        }
        else cout<<q+1<<" "<<w;
   }
return 0;
}
