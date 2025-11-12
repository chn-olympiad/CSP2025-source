#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string s[200005][3], s1, s2, str;
int l[200005];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i=1; i<=n; i++){
		cin >> s[i][1] >> s[i][2];
		l[i] = s[i][1].size();
	}
	for (int i=1; i<=q; i++){
		ans = 0;
		cin >> s1 >> s2;
		for (int j=1; j<=n; j++){
			int id = s1.find(s[j][1]);
			str = s1;
			while (id!=-1){
				str.replace(id, l[j], s[j][2]);
				if (str==s2){
					ans ++;
					break;
				}
				id = s1.find(s[j][1], id+1);
				str = s1;
			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
