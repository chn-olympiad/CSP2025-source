#include<bits/stdc++.h>
using namespace std;
const int N=1e6*5;int ans=-1;
int a[N];int n,k;
void dfs(int x,int cnt){
//	cout<<"*"<<x<<" "<<cnt<<"\n";
	if(x>=n){
		ans=max(ans,cnt);
		cout<<ans;
		exit(0);
//		cout<<"\n";
		return ;
	}
	int sum=0;
	for(int i=x;i<=n;i++){
//		cout<<"/"<<i<<" "<<a[i]<<" "<<sum<<"=";
		sum=sum^a[i];
//		cout<<sum<<"\n";
		if(sum==k){
//			cout<<x<<"->"<<i<<"\n";
			
			dfs(i+1,++cnt);
		} 
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
//4 0 2 1 0 3
