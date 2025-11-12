#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long n,k,a[600001],dp[600001],s[600001];
vector<int> hsh[2000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	hsh[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=s[i-1]^a[i];
		hsh[s[i]].push_back(i);
	}
	for(int i=1;i<=2000001;i++){
		if(!hsh[i].empty())
			sort(hsh[i].begin(),hsh[i].end());
	}
	for(int i=1;i<=n;i++){
		//if(i%10000==0)cout << i << endl;
		if(hsh[s[i]^k].empty())dp[i]=dp[i-1];
		else {
			if(hsh[s[i]^k][0]>i){
				dp[i]=dp[i-1];
				continue;
			}
			int maxn=lower_bound(hsh[s[i]^k].begin(),
				hsh[s[i]^k].end(),i)-hsh[s[i]^k].begin();
			if(maxn==hsh[s[i]^k].size())maxn--;
			if(hsh[s[i]^k][maxn]>i)maxn--;
//			cout << "I'm OK " << i << ' ';
//			cout << hsh[s[i]^k][maxn] << endl;
			dp[i]=max(dp[i-1],dp[hsh[s[i]^k][maxn]]+1);
		}
	}
//	for(int i=0;i<=n;i++)cout << dp[i] << ' ';
//	cout << endl;
	cout << dp[n] << endl;
	return 0;
}
