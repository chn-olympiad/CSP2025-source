#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
vector<string> mp;
vector<string> from;
//map<string, int> hash;
vector<int> dp[N];
struct area {
	int l,r;
};
vector<area> ranges;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++) {
		string f, to;
		cin >> f >> to;
		from.push_back(f);
//		hash[from[i]] = i;
		mp.push_back(to);
	}
	while (q--) {
		for (int i=1;i<=n;i++) {
			dp[i].clear();
		}
		string src, tgt;
		cin >> src >> tgt;
		int len = src.length();
		if (src.size()!=tgt.size()) {
			printf("0\n");
		}
		for (int i=0;i<n;i++) {
			int f;
			string fro = from[i];
			for (int idx = 0;(f = src.find(fro))!=-1;idx+=f+fro.length()-1) {
				int L = fro.length();
				if (tgt.substr(f, L)==mp[i]) {
					ranges.push_back({idx+f, idx+f + L - 1});
				}
				if (f+L >= fro.length()) {
					break;
				}
				fro = fro.substr(f+L);
			}
		}
		for (int len=1;len<=n;len++) {
			int r;
			for (int l=1;(r = l+len-1)<=n;l++) {
				for (area a:ranges) {
					if (a.l==l && a.r==r) {
						dp[l][r] = 1;
						break;
					}
				}
				for (int k=l;k<r;k++) {
					dp[l][r] += dp[l][k] + dp[k+1][r];
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
