#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][3],ma[10005],club[3];
int max(int x;int y){
if(a[x][y]<=a[x][y+1]&&club[x]<=(n/2))
max[x]=a[x][y+1];
}
int main(){
cin>>t;
while(t>0){
cin>>n;
club={0};
for(int j=0;i<n;i++){
for(int i=0;i<3;i++){
cin>>a[j][i];
ma=max(j,i);
}
}
t--;
}
return 0;
}