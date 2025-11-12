#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,a[1000001],s[1001][1001];
bool b=1;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=m*n;i++){cin>>a[i];}
k=a[1];
sort(a+1,a+n*m+1);
reverse(a+1,a+n*m+1);
for(int i=1;i<=m;i++){
        if(b){
    for(int j=1;j<=n;j++){
        s[j][i]=a[n*(i-1)+j];
        b=false;
    }
        }
        else{
         for(int j=n;j>=1;j--){
            s[j][i]=a[n*(i-1)+n-j+1];
            b=true;
         }
        }

}
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i][j]==k){cout<<j<<" "<<i;}
    }
  }
}
