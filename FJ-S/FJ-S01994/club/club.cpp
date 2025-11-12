#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int n, t, res;
bool bi[M];
struct node{
	int zh, bian;
}a[M], b[M], c[M];
bool cmp(node x, node y){
	return x.zh > y.zh;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i].zh >> b[i].zh >> c[i].zh;
			a[i].bian = b[i].bian = c[i].bian = i;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		int tmpa = 1, tmpb = 1, tmpc = 1;
		for(int i = 1; i <= n; i ++){
			if(a[tmpa].zh >= b[tmpb].zh && a[tmpa].zh >= c[tmpc].zh && tmpa != -1 && !bi[tmpa]){
				res += a[tmpa].zh;
				bi[a[tmpa ++].bian] = 1;
			}
			else if(b[tmpb].zh >= a[tmpa].zh && b[tmpb].zh >= c[tmpc].zh && tmpb != -1 && !bi[tmpb]){
				res += b[tmpb].zh;
				bi[b[tmpb ++].bian] = 1;
			}
			else if(tmpb == -1 && a[tmpa].zh >= c[tmpc].zh || tmpc == -1 && a[tmpa].zh >= b[tmpb].zh){
				res += a[tmpa].zh;
				bi[a[tmpa ++].bian] = 1;
			}
			else if(tmpc == -1 && b[tmpb].zh >= a[tmpa].zh){
				res += b[tmpb].zh;
				bi[b[tmpb ++].bian] = 1;
			}
			else{
				res += c[tmpc].zh;
				bi[c[tmpc ++].bian] = 1;
			}
			if(tmpa > n / 2) tmpa = -1;
			else if(tmpb > n / 2) tmpb = -1;
			else if(tmpc > n / 2) tmpc = -1;
		}
		cout << res << endl;
	}
	return 0; 
}
