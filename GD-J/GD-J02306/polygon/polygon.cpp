#include<bits/stdc++.h>
using namespace std;
int a[5001]={0},n;
long long ans=0;
void d(int s,int m,int z,long long all,int be){
	if(m>n){
		return ;
	}
	if(s>n){
		return ;
	}
	if(m<3){
		for(int i = z;i<n;i++){ 
			d(a[i],m+1,i,all+=a[i],be);
		}
	}
	else if((m>=3)&&(m<=n)){
		int big=-1;
		for(long long i = be;i<z;i++){
			big=max(big,a[i]);
		}
		if(all>(2*big)){
			ans++;
		}
		else if(m>=n){
			return ;
		}
		for(int i = z;i<n;i++){
			d(a[i],m+1,i,all+=a[i],be);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d(a[i],1,i,a[i],i);
	}
	cout<<ans%998224353;
	return 0;
} 
