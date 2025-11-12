#include <bits/stdc++.h>
using namespace std;

string s1[200005], s2[200005];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, ans = 0;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++){
		cin >> s1[i] >> s2[i];
	}
	if(q == 1){
		cout << "0\n";
		return 0;
	}
	while(q --){
		string t1, t2;
		cin >> t1 >> t2;
		int n1 = t1.size(), n2 = t2.size();
		if(n1 != n2) {
			printf("0\n");
			continue;
		}
		for(int len = 1; len <= n1; len ++){
			for(int l = 0; l + len - 1 < n1; l ++){
				int r = l + len - 1;
				string x1 = t1.substr(l, r-l+1);
				string x2 = t2.substr(l, r-l+1);
				string x3 = "";
				if(l > 0) x3 = t1.substr(0, l);
				string x4 = t1.substr(r+1, n1-(r+1)+1);
				for(int i = 1; i <= n; i ++){
					if(x1 == s1[i] && x2 == s2[i] && (x3+x2+x4) == t2){
						ans ++;
						break;
					}
				}
				//cout << x3+x2+x4 << ' ' << l << ' ' << r << endl;
			}
		}
		
		printf("%d\n", ans);ans = 0;
	}
	return 0;
}
