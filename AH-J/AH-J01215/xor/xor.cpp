#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define int ll
const int mod=1e9+7;
const int N=5e5+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
unordered_map<int,int> pos;
int n,m;
int a[N]={};
int sum[N]={};
int dp[N]={};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	pos[0]=0;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int tmp=(sum[i]^m);
		if(pos.count(tmp)){
			dp[i]=max(dp[i-1],dp[pos[tmp]]+1);
		}else{
			dp[i]=dp[i-1];
		}
		pos[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
