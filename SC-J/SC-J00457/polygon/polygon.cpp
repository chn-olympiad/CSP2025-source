#include <bits/stdc++.h>
using namespace std;
int b[1001],ans;
int n,a[1001];
int max_(int b[],int sum){
	for(int i=1;i<sum;i++) if(b[i]>b[i+1]) swap(b[i],b[i+1]);
	return b[sum];
}
int min_(int b[],int sum){
	int c=0;
	for(int i=1;i<=sum;i++){
		c+=b[i];
	}
	return c;
}
void dfs(int sum,int q){
	if(sum>q) return;
	if(sum>3&&(2*max_(b,sum)<min_(b,sum))){
		ans++
	}
	for(int i=sum;i<=q;i++){
		b[i]=a[i];
		dfs(sum+1,q);
		dfs(sum+1,q);
//		b[i]=0;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,n);
	cout<<ans;
	return 0;
}