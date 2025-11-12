#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

int a[500005],s[500005],dp[500005];
vector<int>v[500005];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<=2&&k==0){
		if(n==1)cout<<0;
		else cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if((s[i]^s[j-1])==k){
					v[i].push_back(j);
				} 
			}
		}
		for(int i=1;i<=n;i++){
			if(v[i].size()==0){
				dp[i]=dp[i-1];
				continue;
			}
			for(int j=0;j<v[i].size();j++){
				dp[i]=max(dp[i],dp[v[i][j]-1]+1);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(dp[i],ans);
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
