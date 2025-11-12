#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
vector<int>sum[5005],lar[5005];
void dfs(int ox,int x,int rs,int rl){
	for(int i=x+1;i<=n;i++){
		sum[ox].push_back(rs+a[i]);
		lar[ox].push_back(max(rl,a[i]));
		dfs(ox,i,rs+a[i],max(rl,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,a[i],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<sum[i].size();j++){
			if(sum[i][j]>lar[i][j]*2){
				ans=(ans+1)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
