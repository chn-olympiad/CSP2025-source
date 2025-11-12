#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans=0;
void dfs(int dq,int cd){
	if(a[dq]==k&&dq<n){
		dfs(dq+1,cd+1);
	}
	if(a[dq]==k&&dq==n){
		ans=max(ans,cd+1);
		return;
	}
	if(dq>=n){
		ans=max(ans,cd);
		return;
	}
	int sum=a[dq];
	for(int i=dq+1;i<=n;i++){
		sum=sum^a[i];
		if(sum==k){
			dfs(i+1,cd+1);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int sum=0,sum1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
			sum++;
		if(a[i]==0)
			sum1++;
	}
	if(sum==n){
		cout<<n/2;
		return 0;
	}
	if(sum1+sum==n){
		if(k==1){
			cout<<sum;
		}
		else{
			cout<<sum1;
		}
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}