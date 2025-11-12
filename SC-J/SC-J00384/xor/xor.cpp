#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans=0;
int xorsum(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum|a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xorsum(i,j)==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}