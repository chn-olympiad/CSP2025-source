#include<iostream>
using namespace std;
int a[5005];
int n;
long long ans=0;
void dfs(int s,int sum,int l){
	if(s==n+1){
		if(sum>l*2)ans++;
		return;
	}
	dfs(s+1,sum+a[s],max(l,a[s]));
	dfs(s+1,sum,l);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}

