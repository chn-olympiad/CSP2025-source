#include <bits/stdc++.h>
using namespace std;
int c[110];
int cnt, n, m;
int MOD = 998244353;
int b[110];//0表示没走，1表示过不了走，2表示成功面试，3表示因为人太多了才走 
string s;
bool is_yes = 0;
void dfs(int x, int time, int agreement, int unget){
	int n1 = 0;
	for (int i = 0; i < n; i++){
		if (unget >= c[i] && b[i] == 0){
			n1++;
			b[i] = 3;
		} else if (unget < c[i] && b[i] == 3){
			b[i] = 0;
		}
	}
	unget += n1;
	//printf("x:%d time:%d agreement:%d unget:%d\n", x, time, agreement, unget);
	if (agreement == m && time == n-1){
		cnt = (cnt+1)%MOD;
		//printf("cnt:%d\n", cnt);
	}
	for (int i = 0; i < n; i++){
		if (b[i] == 1 || b[i] == 2 || b[i] == 3){
			continue;
		} else {
			if (s[time+1] == '1' && unget < c[i]){
				b[i] = 2;
				dfs(i, time+1, agreement+1, unget);
				b[i] = 0;
			} else if (s[time+1] == '0'){
				b[i] = 1;
				dfs(i, time+1, agreement, unget+1);
				b[i] = 0;
			} else if (unget < c[i]){
				b[i] = 3;
				dfs(i, time+1, agreement, unget+1);
				b[i] = 0;
			}
		}
	}
	
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	for (int i = 0; i < n; i++){
		if (i == 2) is_yes = 1;
		if (s[0] == '1' && c[i] >= 1){
			b[i] = 2;
			dfs(i, 0, 1, 0);
			b[i] = 0;
		} else {
			b[i] = 1;
			dfs(i, 0, 0, 1);
			b[i] = 0;
		}
		
	}
	cout << cnt;
	return 0;
}
