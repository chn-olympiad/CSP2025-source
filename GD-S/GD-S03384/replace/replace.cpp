#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	map <string, string> mp;
	string s1, s2;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	string t1, t2;
	while(q--){
		cin >> t1 >> t2;
		int ans = 0;
		int len = t1.size();
		for(int i = 0; i < len; i++){
			for(int j = i; j < len; j++){
				string y;
				for(int k = i; k <= j; k++){
					y += t1[k];
				}
				string _y = mp[y];
				string x, z;
				for(int k = 0; k < i; k++){
					x += t1[k];
				}
				for(int k = j + 1; k < len; k++){
					z += t1[k];
				}
				if(x + _y + z == t2) ans++;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
