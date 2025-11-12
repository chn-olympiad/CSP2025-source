#include<bits/stdc++.h>
using namespace std;
int n,q;
char a[][];
int sum;
int main( ){
cin>>n>>q;
for(int i=1;i<=q;i++){
      for(int j=1;j<=i;j++){
      cin>>a[i][j];
}
}
for(int i=-1;i<=q;i++){
      for(int j=1;j<=i;j++){
if(a[i][j]!=a[i+1][j]){
sum++;
}
}
cout<<sum<<endl;
}
return 0;
}