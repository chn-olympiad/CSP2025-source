#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
int i,n,m,ans=1,k,temp,nn,mm;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int a[n*m+2];
for(int w=1;w<=n*m;w++){
	cin>>a[w];
	if(ans==1){k=a[w];ans--;}
	}
for(int j=1;j<=n*m;j++){
	for(i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){temp=a[i];a[i]=a[i+1];a[i+1]=temp;}
	}
}
	
int i2=1;
while(k!=a[i2]){
	i2++;
}
k=i2;

if(k%n==0)mm=k/n;
else mm=(k/n)+1;
int q=k%(2*n);
if(q==0)nn=1;
for(int e=1;e<=2*n-1;e++){
	if(e<=n){
		if(q==e){
		nn=e;
		break;	
		}
	}
	if(e>n&&e<=2*n-1){
		if(q==e){
		nn=2*n+1-e;
		break;
		}
	}
}

cout<<mm<<" "<<nn;

return 0;
}