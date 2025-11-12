#include<iostream>
using namespace std;
int a[1000000]={},ans;
bool p[1000000];
int yh(int l,int r){
	int sum=0;
	if(r=l) {
		return a[l]&a[r];
	}
	for(int i=l;i<r;i++){
		sum+=a[i]^a[i+1];
	}
	return sum;
}
bool pd(int l,int r){
	for(int i=l;i<=r;i++){
		if(p[i]==1)
			return 0;
	}
	return 1;
}
void sz(int l,int r){
	for(int i=l;i<=r;i++){
		p[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout)
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		 	if(pd(i,j)&&yh(i,j)==k){
		 		ans++;
		 		sz(i,j);
			 }
		}
	}
	cout<<ans;
	return 0;
}
