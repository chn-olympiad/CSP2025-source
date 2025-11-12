#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
freopen("club.in ","r",stdin);
freopen("club.out","w",stdout);
int t,n,sum[100]={},max[100][100]={},d[2];
cin>>t;
for(int i=0;i<t;i++){
cin>>n;
for(int j=0;j<n;j++){
for(int k=0;k<3;k++){
cin>>a[j][k];
max[i][j]=a[j][k];
if(max[i][j]<a[j][k]){
max[i][j]=a[j][k];
}
}
}
}
for(int i=0;i<t;i++){
for(int j=0;j<n;j++){
sum[i]+=max[i][j];
}
}
for(int i=0;i<t;i++){
cout<<sum[i]<<endl;
}
return 0; 
}

