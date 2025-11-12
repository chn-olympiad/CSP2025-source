#include<bits/stdc++.h>
using namespace std;
int a[11][11],at[11][11],o[121],n,m,a1,c,r,k1,k2,l,k=1;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cin>>a[i][j];o[k]=a[i][j];k++;}}
sort(o,o+k);a1=a[1][1];
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
		at[i][j]=o[m*n-i*n-j+n+1];}}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(at[i][j]==a1){
		    k1=i;k2=j;
			c=k1;l=k1%2;
            if(l==1)    r=k2;
            else    r=n-k2+1;
            cout<<c<<" "<<r;break;}}}
return 0;}