#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans = 0;
vector<int> ad; 
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		int tmp; cin>>tmp;
		ad.push_back(tmp);
	}
	for(int i = 0; i<ad.size();++i){
		for(int j = i; j<ad.size();++j){
			int d = 0;
			for(int l = i;l<=j;++l) d ^= ad[l];
			if(d == k) {
				ans++;
				i = j; // 不可以重复 
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
