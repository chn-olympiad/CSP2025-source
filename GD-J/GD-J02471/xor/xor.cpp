#include<bits/stdc++.h>
using namespace std;

int n, k, xr[500005], a[500005], top = 0, preend, ans;
map<int, int> mp;
struct Stage{
	int l, r;
}p[1000005];
bool cmp(Stage a, Stage b){
	if(a.r == b.r) return a.l > b.l;
	else return a.r < b.r;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	mp[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
		if((a[i] ^ k) == 0){
			top++;
			p[top].l = i;
			p[top].r = i;
			xr[i] = 0;
		} 
		else if(mp[xr[i] ^ k] != 0){
			top++;
			p[top].l = mp[xr[i] ^ k] + 1;
			p[top].r = i;
		}
		else if((xr[i] ^ k) == 0 && mp[xr[i] ^ k] == 0){
			top++;
			p[top].l = 1;
			p[top].r = i;
		}
		mp[xr[i]] = i;
	} 
	sort(p + 1, p + top + 1, cmp);
	preend = 0;
	for(int i = 1; i <= top; i++){
		if(preend < p[i].l){
			ans++;
			preend = p[i].r;
		}
	}
	cout << ans << "\n"; 
	return 0;
}
