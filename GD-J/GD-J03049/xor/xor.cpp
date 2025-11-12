#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define fi first
#define se second

int n, k, a[500005], s[500005], Kbit[22], cnt, ans, b[1049000], C[500005], ptr[21];
deque<int> bit[21];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> k;
	bool teshuxingzhi = 1;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
		teshuxingzhi &= (a[i] == 0 || a[i] == 1);
	}
	
	if(k == 0){ // 10 pts
		for(int i=1; i<=n; ++i){
			++ b[a[i]];
		}
		for(int i=0; i<=1048576; ++i){
			ans = max(ans, (i ? (b[i] / 2) : b[i]));
		}
		return cout << ans, 0;
	}
	
	if(teshuxingzhi){ // 20 pts
		for(int i=1; i<=n; ++i) {
			if(a[i] == k) ++ ans;
		}
		return cout << ans, 0;
	}
	
	for(int i=20; i>=0; --i){
		if((k >> i) & 1) Kbit[++ cnt] = i;
	}
	for(int p=1; p<=n; ++p){ // 玄学 pts 
		int res = 0;
	for(int i=p; i<=n; ++i){
		for(int j=1; j<=cnt; ++j){
			if((a[i] >> Kbit[j]) & 1){
				bit[j].push_back(i);	
			}
		}
		bool flag = 1;
		for(int j=1; j<=cnt; ++j){
			if(bit[j].empty()) flag = 0;
		}
		if(flag){
			++ res;
			for(int j=1; j<=cnt; ++j){
			    bit[j].clear(); bit[j].shrink_to_fit();
			}
		}
	}
	for(int j=1; j<=cnt; ++j){
		bit[j].clear(); bit[j].shrink_to_fit();
	}
	int ans2 = 0;
	for(int i=p; i<=n; ++i){
		for(int j=1; j<=cnt; ++j){
			if((a[i] >> Kbit[j]) & 1){
				bit[j].push_back(i);	
			}
		}
		bool flag = 1;
		for(int j=1; j<=cnt; ++j){
			if(bit[j].empty()) flag = 0;
		}
		if(flag){
			for(int j=1; j<=cnt; ++j){
				if(! (bit[j].size() & 1)){
					++ ans2;
				    break;
				}
			}
			for(int j=1; j<=cnt; ++j){
			    bit[j].clear(); bit[j].shrink_to_fit();
			}
		}
	}
	ans = max(res - ans2, ans); // 假了，人要炸了！！！！！！！ 
}
	cout << ans << '\n';
	return 0;
}
// 电脑左shift炸了，恐怖 || 我怎么想不出整洁，都拆位了（ 
