#include <iostream>
#include <cstdio>
using namespace std;
int a[11][11],m,n,x;
int main(){
cin >> n >> m;
for (int i=1;i<=m;i++){
for( int j=1;j<=n;j++){
cin >>a[i][j];
}
}
x=a[1][1];
for (int i=1;i<=m;i++){
for( int j=1;j<=n;j++){
if(a[i][j]=x){
cout << i << " " << j;
}
}
}

return 0;
}
