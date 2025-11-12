#include <bits/stdc++.h>
using namespace std;

int n , q;
string s[200010][2];

signed main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) cin >> s[i][1] >> s[i][2];
	for(int i = 1 ; i <= q ; i++){
		int cnt = 0;
		string s1 , s2;
		cin >> s1 >> s2;
		int st = -1 , ed = -1;
		for(int i = 0 ; i < s1.size() ; i++){
			if(s1[i] != s2[i] && st == -1) st = i;
			if(s1[i] == s2[i] && st != -1) ed = i - 1;
		}for(int j = 1 ; j <= n ; j++){
			if(s[j][1].size() > s1.size()) continue;
			for(int k = 0 ; k < s[j][1].size() ; k++){
				int f = 0;
				if(s[j][1][k] == s1[st] && s[j][2][k] == s2[st])
					for(int l = 1 ; l <= ed - st ; l++){
						if(s[j][1][k + l] != s1[st + l] || s[j][2][k + l] != s2[st + l])
							break;
						if(l == (ed - st)) f = 1;
					}
				if(f){
					for(int l = 1 ; l <= k ; l++)
						if(s[j][1][k - l] != s1[st - l] || s[j][2][k - l] != s2[st - l]){f = 0; break;}
					if(f)
						for(int l = 1 ; l <= s[j][1].size() - k - 1 ; l++)
							if(s[j][1][k + l] != s1[st + l] || s[j][2][k + l] != s2[st + l]){f = 0; break;}
				}if(f) cnt++;
			}
		}cout << cnt << endl;
	}return 0;
}
 
