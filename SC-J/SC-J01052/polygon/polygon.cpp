#include<bits/stdc++.h>
using namespace std;

long long a[5001] = {0};
long long s[5001] = {0};
bool vis[5001] = {0};
long long tot = 0;
int n;

long long dfs(int now, int k, long long maxx){
	if(now == k){
		long long sum = 0;
		for(int i=0;i<n;i++){
			sum+=s[i];
		}
		if(sum>maxx*2){
			tot++;
			tot%=998244353;
		}
		return tot;
	}
	dfs(now+1,k,maxx);
	for(int i=1;i<=n;i++){
		if(vis[i] == 0){
			vis[now] = 1;
			s[now] = i;
			dfs(now+1,k,max(maxx,a[i]));
			vis[now] = 0;
		}
	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,-1);
	}
	cout<<tot;
	return 0;
}
//998244353