#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],s[500010];
map<int,vector<int>> mp;
int last=0;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0].push_back(0);
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		mp[s[i]].push_back(i);
	}
	int ans=0;
	for(int i = 1; i<=n; i++) {
		int f=s[i]^k;
		if(k==a[i]) {
			ans++;
			last=i;
		} else if(mp.find(f)!=mp.end()&&mp[f].size()>0) {
			if(last&&mp[f].size()>0) mp[f].erase(mp[f].begin(),lower_bound(mp[f].begin(),mp[f].end(),last));
			
			if(mp[f].size()>0&&mp[f][0]+1<i) {
				ans++;
				last=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
