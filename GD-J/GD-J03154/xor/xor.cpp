# include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct node{
	int l, r;
};
vector <node> v;
int n, k, a[N], f[1010][1010], vis[1010], ans, b[N];
bool cmp(node a, node b){
	if(a.r - a.l != b.r - b.l)return a.r - a.l < b.r - b.l;
	if(a.r != b.r)return a.r < b.r;
	return a.l < b.l;
}
void s1(){
	for(int i = 1; i <= n; i ++){
		b[i] = b[i - 1] + a[i];
	}
	int la = 0;
	for(int i = 1; i <= n; i ++){
		if((b[i] - b[la]) % 2 == k)ans ++;
		la = i;
	}
	cout << ans;
}
void s2(){
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			f[i][j] = (f[i][j - 1] xor a[j]);
			if(f[i][j] == k){
				bool ok = 0;
				for(int x = i; x <= j; x ++){
					if(vis[x] == 1){
						ok = 1;
						break;
					}
				}
				if(!ok){
					v.push_back({i, j});
				}
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(auto x : v){
		bool ok = 0;
		for(int i = x.l; i <= x.r; i ++){
			if(vis[i] == 1){
				ok = 1;
				break;
			}
		}
		if(!ok){
			for(int i = x.l; i <= x.r; i ++)vis[i] = 1;
			ans ++;
		}
	}
	cout << ans;
}
int main(){
	freopen("xor.in1", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool flag = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(!(a[i] == 0 || a[i] == 1))flag = 1;
	}
	if(!flag)s1();
	else s2();
	return 0;
}
