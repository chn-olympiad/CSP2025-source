#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[N],j,sum[N];
int ans;
bool check(int l,int r){
	for(int i=r;i>=l;i--){
		if((sum[r]^sum[i-1])==k){
			return 1;
		}
	}
	return 0;
}
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	if(a[1]==k){
		f[1]=1;
		j=1;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==0){
			continue;
		}
		if(check(j+1,i)){
			f[i]=f[j]+1;
			j=i;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	
	return 0;
}
// ^
/*
4 0
2 1 0 3
*/
