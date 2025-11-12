#include<bits/stdc++.h>
using namespace std;
long long a[1000010],z,n,m,ans,zz;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	cin>>z;
	for(int i=1;i<=(n*m)-1;i++){
		long long z2;
		cin>>z2;
		if(z2>z) ans++;
	}
	if((ans/m+1)%2==0){
		zz=m-ans%m;
		if(zz==0){
			zz=m;
		
		}
	}	
	else{
		zz=ans%m+1;
		if(zz==0){
			zz=1;
		}
	}
	cout<<ans/m+1<<' '<<zz;
	
	
	
	return 0;
}
