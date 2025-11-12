#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans,g;
void dfs(int x,int k,int sum){
	if(x==g){
		for(int i=n;i>=k;i--){
			if(sum>a[i]){
				ans+=i-k+1;
				ans%=998244353;
				return;
			}
		}
		return;
	}
	for(int i=k;i<n;i++){
		dfs(x+1,i+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(g=2;g<n;g++){
		dfs(0,1,0);
	}
	cout<<ans;
	return 0;
}

