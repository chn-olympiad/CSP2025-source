#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn = 2e5 + 9, maxm = 5e6 + 9, seed = 1337;
ull hs[maxn][2], sqt[maxm], ha[maxm], hb[maxm];
string s[maxn][2];
string a, b;
int n, q;
void init_hash(){
	sqt[0] = 1;
	for(int i = 1;i <= 5e6;i++) sqt[i] = sqt[i - 1] * seed;
	for(int i = 1;i <= n;i++){
		int sz = s[i][0].size();
		hs[i][0] = hs[i][1] = 0;
		for(int j = 0;j < sz;j++){
			hs[i][0] = hs[i][0] * seed + s[i][0][j];
			hs[i][1] = hs[i][1] * seed + s[i][1][j];
		}
	}
}
void init(){
	int sz = a.size();
	ha[0] = hb[0] = 0;
	for(int i = 1;i <= sz;i++){
		ha[i] = ha[i - 1] * seed + a[i - 1];
		hb[i] = hb[i - 1] * seed + b[i - 1];
	}
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
    init_hash();
    while(q--){
    	cin >> a >> b;
    	if(a.size() != b.size()){
			cout << 0 << "\n";
    		continue;
		}
		int sz = a.size();
		int l = -1, r = -1;
		init();
		for(int i = 0;i < sz;i++){
			if(a[i] != b[i] && l == -1) l = i + 1;
			if(a[i] != b[i]) r = i + 1;
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			int sm = s[i][0].size();
			int lj = max(1, r - sm + 1), rj = min(sz - sm + 1, l);
			for(int j = lj;j <= rj;j++){
				int lf = j, rf = j + sm - 1;
				if((ull)ha[rf] - ha[lf - 1] * sqt[lf - 1] == (ull)hs[i][0] && (ull)hb[rf] - hb[lf - 1] * sqt[lf - 1] == (ull)hs[i][1]){
					cnt++;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
    return 0;
}

