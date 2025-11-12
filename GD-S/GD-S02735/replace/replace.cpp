#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 200005

int cnt[30];
string s[MAXN][5], t[5];
int poss[MAXN][5], post[5]; 
int n, q, LL; 
bool xzB = true;
int main(void){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
		LL += s[i][1].size() * 2;
		for(int j = 0; j < s[i][1].size(); j++){
			if(s[i][1][j] != 'a' && s[i][1][j] != 'b')
				xzB = false;
			if(s[i][1][j] == 'b' && poss[i][1])
				xzB = false;
			if(s[i][1][j] == 'b')
				poss[i][1] = j;
		}
		for(int j = 0; j < s[i][2].size(); j++){
			if(s[i][2][j] != 'a' && s[i][2][j] != 'b')
				xzB = false;
			if(s[i][2][j] == 'b' && poss[i][2])
				xzB = false;
			if(s[i][2][j] == 'b')
				poss[i][2] = j;
		}
	}
	if(xzB && LL > 200){
		while(q--){
			int ans = 0;
			cin >> t[1] >> t[2];
			for(int j = 0; j < t[1].size(); j++)
				if(t[1][j] == 'b')
					post[1] = j;
			for(int j = 0; j < t[2].size(); j++)
				if(t[2][j] == 'b')
					post[2] = j;
			for(int i = 1; i <= n; i++){
				if(poss[i][1] - poss[i][2] == post[1] - post[2] && 			//b相对位置一样 
					post[1] >= poss[i][1] && 								//左边能放得下 
					t[1].size() - post[1] >= s[i][1].size() - poss[i][1]){	//右边能放得下 
					ans++; 
				}
			}
			printf("%d\n", ans);
		}	
	}
	else{
		while(q--){
			int ans = 0;
			cin >> t[1] >> t[2];
			int pos = 0;
			for(int i = 1; i <= n; i++){
				string tmp = t[1];
				int pos = t[1].find(s[i][1]);
				while(pos >= 0 && pos < t[1].size()){
					string X = tmp.substr(0, pos);
					string Z = tmp.substr(pos + s[i][1].size());
					string chg = X + s[i][2] + Z;
					if(chg == t[2])
						ans++;
					tmp[pos] = '#';
					pos = tmp.find(s[i][1]);
				}
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
