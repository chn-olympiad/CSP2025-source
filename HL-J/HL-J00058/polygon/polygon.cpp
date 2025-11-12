#include<bits/stdc++.h>
using namespace std;
long long n,arr[1000000],maxn=0;
long long ans;
void dfs(int k){
	for(int i=1;i<=n;i++){
		ans=max(maxn,arr[i]);
	}
	for(int i=1;i<=n;i++){
		if(k+=arr[i])
		k+=arr[i];
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	return 0;

	
}
