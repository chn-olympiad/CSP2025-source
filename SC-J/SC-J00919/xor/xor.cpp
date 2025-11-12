#include<iostream>
using namespace std;
int n,k,a[500003],sum;
bool dp[500003][500003];
int f(int l,int r){
	int x,y,z;
	if(l==r){
		x=a[r];
	}
	else{
		if(!dp[l][r-1]){
			x=f(l,r-1)^a[r];
			dp[l][r-1]=1;
		}
		else z=f(l,r-1)^a[r];
		if(!dp[l+1][r]){
			y=f(l+1,r)^a[r];
			dp[l+1][r]=1;
		}
		else z=f(l+1,r)^a[r];
	}
	if(x==k)sum++;
	if(y==k)sum++;
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ff=f(1,n);
	cout<<sum;
	return 0;
}