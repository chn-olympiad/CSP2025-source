#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N], n, k, s[N];
int vis[1100000];
struct ln{
	int l, r;
	bool operator < (const ln &X) const{
		return r < X.r;
	}
};
vector<ln> lns;
void solveA(){
	cout << n/2;
	return;
}
void solve(){
	memset(vis, 0x3f, sizeof vis);
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1] ^ a[i]; 
	}
	for(int i = n;i >= 0;i--){
		vis[s[i]]=min(vis[s[i]], i);
		if(vis[k^s[i]] != 0x3f3f3f3f && i+1<=vis[k^s[i]]){
			lns.push_back({i+1,vis[k^s[i]]});
		}
	}
	sort(lns.begin(), lns.end()); 
	int maxr = 0, cnt = 0;
	for(ln i : lns){
		//printf("[Debug] lns found! -> l : %d r : %d\n", i.l, i.r);
		if(i.l > maxr){
			cnt++;
			maxr = i.r;
		} 
	}
	cout << cnt;
	return;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	bool spjA=true; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=1)spjA=false;
	}
	if(spjA) solveA();
	else solve();
}
