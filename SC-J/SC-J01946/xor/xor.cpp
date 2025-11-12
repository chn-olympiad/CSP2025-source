#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n,k,mp[N],ans=0;
unordered_map<int,int>dp[N];
pair<int,int>ve={0,0};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>dp[i][i];
	for(int j=1;j<=n;j++)
		for(int i=ve.first+1;i<=j;i++)
			if(i>ve.first){
				dp[j][i]=(dp[j-1][i]^dp[j][j]);
				if(dp[j][i]==k){ve.first=j,ve.second++;break;}
			}
	cout<<ve.second<<'\n';
	return 0;
}