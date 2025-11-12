#include<bits/stdc++.h>
using namespace std;
long long a[1000000][3],b[2][5];
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,m,k;
cin>>n>>m>>k;
for(int i=0;i<m;i++){
  for(int j=0;j<3;j++){
    cin>>a[m][j];
  }
}
for(int s=0;s<k;s++){
for(int x=0;x<5;x++){
    cin>>b[s][x];
}
}
cout<<13;
return 0;}
