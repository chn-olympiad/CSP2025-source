#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,t,a[500005],p[500005],dp[500005],n,m,ans;
unordered_map<int,vector<pair<int,int>>> ve;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			for(auto x:ve[j]){
				ve[j+1].push_back({x.first+a[i],a[i]});
			}
		}
		ve[1].push_back({a[i],a[i]});
	}
	for(int j=3;j<=n;j++){
		for(auto x:ve[j]){
			if(x.first>x.second*2)ans++;
		}
	}
	cout<<ans;
	return 0;
}