#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[5100];
void dfs(int temp,long long sum,int last_){
	for(int i=last_+1;i<n;i++){
		if(temp>=3){
			if(sum>a[i]){
				ans++;
			}
		}
		dfs(temp+1, sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool if1=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)if1=0;
	}
	if(if1){
		for(int i=3;i<=n;i++){
			long long u=1;
			for(int j=0;j<i;j++){
				u*=(n-j);
				u/=(j+1);
				u%=998244353;
			}
			ans+=u;
			ans%=998244353;
		}
	}
	sort(a,a+n);
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}