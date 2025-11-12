#include<bits/stdc++.h>
#define int long long

using namespace std;

const int SIZN = 5e5 + 10;

int n,k;
int sums[SIZN];
map<int,vector<int> > mp;
int ans;
int ls;
int find(vector<int> v,int num){
	int l = 0,r = v.size() - 1;
	int mid = 0;
	while(l < r){
		mid = (l + r) >> 1;
		if(v[mid] > num)r = mid - 1;
		else l = mid + 1;
	}
	if(v[l] >= num)l--;
	if(l < 0)return -1;
	else return v[l];
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	mp[0].push_back(0);
	for(int i = 1 ; i <= n ; i++) {
		int nums;
		cin >> nums;
		sums[i] = sums[i - 1] ^ nums;
		mp[sums[i]].push_back(i);
	}
	for(int i = 1 ; i <= n ; i++) {
		int f = k ^ sums[i];
		if(mp.count(f)){
			int pos = find(mp[f],i);
			if(pos >= ls && pos < i){
				ls = i;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
