#include<bits/stdc++.h>
using namespace std;
int a[1001],andy[11][11];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,r;
cin>>n>>m;
for(int i=0;i<n*m;i++) cin>>a[i];
r = a[0];
sort(a,a+n*m);
for(int i=n*m-1;i>=0;i--)
if(a[i]==r){
r = n*m-i;
break;
}
int i=0,j=0,s=0;
bool c=0;
do{
if(c==0){
i++,s++;
if(i==n+1) i--,j++,c=1;
}
andy[i][j] = s;
if(c==1){
i--,s++;
if(i==0) i++,j++,c=0;
}
andy[i][j] = s;
}while(s<n*m);
for(int i=1;i<=n;i++)
for(int j=0;j<m;j++)
if(andy[i][j]==r){
cout<<j+1<<' '<<i;
break;
}
return 0;
}
