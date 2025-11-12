#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int pre[500005];
bool useless[500005];
int get(int l,int r) {
	return pre[r]^pre[l-1];
}
vector<pair<int,int> > v;
vector<pair<int,int> > u;
map<int,int> mp;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p=1;
	int maxi=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)p=0;
		maxi=max(maxi,a[i]);
	}
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]^a[i];
	}
	mp[0]++;
	for(int i=1; i<=n; i++) {
		if(mp.find(pre[i]^k)!=mp.end()) {
			ans++;
			mp.clear();

		}
		mp[pre[i]]++;
	}
	cout<<ans;
	return 0;
}
/*
oh no
not found solution
ok 1e3 would 60pts?
maybe #13 add another 5pts
65pts?
rp++rp++rp++rp++rp++rp++rp++rp++rp++
oh yeah I found soulution !!!!
last 5 minute
map is my god.
map so useful.
i hate xor.
but pre is also useful;
2 3 3 0
*/
