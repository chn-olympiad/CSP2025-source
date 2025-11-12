#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n][m];
int b[i][j];
for(int i=1;i<=n;i++){
for(int j=0;j<+m;j++){
cin>>b[i][j];
}
}
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
a[i][j]=b[i][j];
}
sort(a,a+m*n);
 for(int i=1;i<=n;i++){
 for(int j=1;j<=m;j++){
 if(a[i][j]==b[1][1]){
 cout<<i<<' '<<j;
 }
 }
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
 }
