#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],dp[5005];
bool vis[25];
vector<int> as;
vector<vector<int>> gg;
void dfs(int x){
	if(x==0){
		as.clear();
		int sum=0,maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				maxx=max(maxx,a[i]);
				as.push_back(i);
			}
		}
		if(sum>2*maxx){
			gg.push_back(as);
		}
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(x-1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool status=true;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1) status=false;
	}
	if(status){
		dp[1]=0;
		dp[2]=0;
		for(int i=3;i<=n;i++){
			int x=i-2;
			dp[i]=(dp[i-1]+x)%mod;
		}
		cout <<dp[n] <<endl;
	}else{
		for(int i=3;i<=n;i++){
			as.clear();
			dfs(i);
		}
		sort(gg.begin(),gg.end());
		auto akioi=unique(gg.begin(),gg.end());
		cout <<akioi-gg.begin() <<endl;
	}
	return 0;
}
