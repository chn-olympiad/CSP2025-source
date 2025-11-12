#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],ans,dp[500005],f[500005];
bool pre[500005][25];
string kk,s[500005];
string to_2(int x){
	string ss;
	char y=0;
	for(int i=1;i<=25;i++)ss+=y;
	int cnt=0;
	while(x){
		ss[++cnt]+=x%2;
		x/=2;
	}
	return ss;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=to_2(a[i]);
		for(int j=1;j<=24;j++){
			pre[i][j]=(pre[i-1][j]!=s[i][j]);
		}
	}
	kk=to_2(k);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int ok=1;
			for(int w=1;w<=24;w++){
				if(abs(pre[i][w]-pre[j-1][w])!=kk[w]){
					ok=0;
					break;
				}
			}
			if(ok){
				f[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(f[i])dp[i]=max(dp[i],dp[f[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}