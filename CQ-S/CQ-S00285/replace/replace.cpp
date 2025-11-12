#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5e6 + 10;
bool stt;
#define ull unsigned long long
int Base[2] = {131, 1331};
string s[N][3];
ull H[4][2][M]; 
ull b[2][M];
bool flagA, flagB;
int n, q;
ull getH(int i, int k, int l, int r){
	int siz = r - l + 1;
	return (H[i][k][r]) - (H[i][k][l - 1]) * b[k][siz];
}
bool cmp(int x, int y, int l, int r, int _l, int _r){
	for(int i = 0; i < 2; i++){
		if(getH(x, i, l, r) != getH(y, i, _l, _r)){
			return false;
		}
	}
	return true;
}
void solve(){
	string t1;
	string t2;
	cin >> t1 >> t2;
	if(t1.size() != t2.size()){
		printf("0\n");
		return;
	}
	int st = -1, ed = -1;
	for(int i = 0; i < t1.size(); i++){
		if(t1[i] != t2[i] && st == -1) st = i;
		if(t1[i] != t2[i]) ed = i;
	}
	int sizc = ed - st + 1;
	for(int i = 0; i < 2; i++){
		H[0][i][0] = 0;
		for(int j = 1; j <= t1.size(); j++){
			H[0][i][j] = H[0][i][j - 1] * Base[i] + t1[j - 1];
		}	
	}
	for(int i = 0; i < 2; i++){
		H[1][i][0] = 0;
		for(int j = 1; j <= t2.size(); j++){
			H[1][i][j] = H[1][i][j - 1] * Base[i] + t2[j - 1];
		}	
	}
	ull cy0[2] =  {getH(0, 0, st + 1, ed + 1), getH(0, 1, st + 1, ed + 1)};
	ull cy1[2] =  {getH(1, 0, st + 1, ed + 1), getH(1, 1, st + 1, ed + 1)};	  
	int ans = 0;
	for(int I = 1; I <= n; I++){		
		for(int i = 0; i < 2; i++){
			H[2][i][0] = 0;
			for(int j = 1; j <= s[I][0].size(); j++){
				H[2][i][j] = H[2][i][j - 1] * Base[i] + s[I][0][j - 1];
			}	
		}
		for(int i = 0; i < 2; i++){
			H[3][i][0] = 0;
			for(int j = 1; j <= s[I][1].size(); j++){
				H[3][i][j] = H[3][i][j - 1] * Base[i] + s[I][1][j - 1];
			}	
		}		
		for(int i = 1; i <= s[I][1].size(); i++){
			if(i - sizc + 1 < 1) continue;
			int tl = i - sizc + 1, tr = i;
			if(getH(2, 0, tl, tr) == cy0[0] && getH(2, 1, tl, tr) == cy0[1] && getH(3, 0, tl, tr) == cy1[0] && getH(3, 1, tl, tr) == cy1[1]){
				int tll = st - (tl - 1) + 1;
				int trr = ed + s[I][1].size() - tr + 1;
				if(cmp(0, 2, tll, trr, 1, s[I][1].size()) && cmp(1, 3, tll, trr, 1, s[I][1].size())){
					ans++;
				}		
			}
		}
	}	
	printf("%d\n", ans);
}
bool edd;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	for(int i = 0; i <= 1; i++){
		b[i][0] = 1;
		for(int j = 1; j <= 5e6; j++){
			b[i][j] = b[i][j - 1] * Base[i];
		}
	} 
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		solve();
	}
	
}

