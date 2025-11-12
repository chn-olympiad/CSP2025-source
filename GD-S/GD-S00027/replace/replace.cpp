#incluce <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q;
strings s[MAXN][2], t[MAXN][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1;i <= q;i++){
		cin >> t[i][0] >> t[i][1];
		int len = t[i][0].size();
		for(int j = 0;j < len;j++){
			for(int k = 1;k <= n;k++){
				int tlen = s[k].size();
				bool flag = 1;
				for(int l = 0;l < tlen;l++){
					if(t[j + l][0] != s[l][0]){
						flag = 0;
					} 
				}
				if(flag){
					for(int )
				}
			}
		}
	}
	
	return 0;
} 
