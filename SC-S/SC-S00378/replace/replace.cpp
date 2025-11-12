#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
string s[MAXN][3];
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < s1.size(); j++){
				bool flag = true;
				for(int k = 0; k < s[i][1].size(); k++){
					if(s1[j + k] != s[i][1][k]){
						flag = false;
					}
				}
				if(flag == true){
					string t = s1;
					for(int k = 0; k < s[i][1].size(); k++){
						t[j + k] = s[i][2][k];
					}
					if(t == s2){
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}