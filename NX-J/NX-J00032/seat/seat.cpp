#include <bits/stdc++.h>
using namespace std;
int main(){
// freopen("seat.in,"w",stdin)
 //freopen("seat.in,"r",stdout)
 int n,m,a[101][101],k=0,s=0;
 int c=1,r=1;
 cin>>n>>m;
 for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){

        cin>>a[i][j];
         k=a[0][0];
         s=a[i-1][j];
        if(k<s){
            if(c%2!=0){
                r=r+1;
                if(r>n){
                    c=c+1;
                }
            }

             if(c%2==0){
                r=r-1;
                if(r<1){
                    c=c+1;
            }
                }
        }
    }
}
cout<<c<<" "<<r;
return 0;
}
