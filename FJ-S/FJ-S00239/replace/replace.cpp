#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][2], x, y;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d", &n, &q);
	if(q > 10004 || n > 10004){
		for(int i = 1; i <= q; i++){
			printf("0\n");
		}return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		int ans = 0;
		for(int j = 1; j <= n; j++){
			int lx = x.find(s[j][0]), ly = 0, lz = 0, len = s[j][0].size();
			int siz = x.size();
			if(lx > -1){
				ly = lx - 1;
				lz = lx + len;
				string a = x.substr(0, ly + 1);
				string b = s[j][1];
				string c = x.substr(lz, siz - lz);
				if(a + b + c == y)ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

