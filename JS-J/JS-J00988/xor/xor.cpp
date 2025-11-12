#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],dp[500005];
map<int,int> m;
vector<pair<int,int> > v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	m[k]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(i+1<=n)m[b[i]^k]=i+1;
		if(m[b[i]]!=0&&m[b[i]]<=i)v.push_back(make_pair(m[b[i]],i));
	}
	for(int i=0;i<v.size();i++){
		int dx=v[i].first;
		int dy=v[i].second;
		dp[dy]=max(dp[dy],dp[dx-1]+1);
		for(int j=dy+1;j<=n;j++)dp[j]=dp[dy];
	}
	int maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
}
