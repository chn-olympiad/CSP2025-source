#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 4;
struct Node{
	int x, sz;
} a[N], b[N], c[N];
bool cmp(Node t1, Node t2){
	return t1.sz > t2.sz;
}
int T, n, jl[N][3], ct, ct2, ct3, ans, sx[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("out.txt", "w", stdout);	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		ct = ct2 = ct3 = ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> jl[i][0] >> jl[i][1] >> jl[i][2];
			if(jl[i][0] >= jl[i][1] && jl[i][0] >= jl[i][2]) a[++ct] = (Node) {i, jl[i][0]};
			else if(jl[i][1] >= jl[i][0] && jl[i][1] >= jl[i][2]) b[++ct2] = (Node) {i, jl[i][1]};
			else c[++ct3] = (Node) {i, jl[i][2]};
		}
		for(int i = 1;i <= ct;i++) ans += a[i].sz;
		for(int i = 1;i <= ct2;i++) ans += b[i].sz;
		for(int i = 1;i <= ct3;i++) ans += c[i].sz;
		if(ct > n / 2){
			for(int i = 1;i <= ct;i++){
				int xw = a[i].x;
				sx[i] = jl[xw][0] - max(jl[xw][1], jl[xw][2]);
			}
			sort(sx + 1, sx + ct + 1);
			for(int i = 1;i <= ct - n / 2;i++) ans -= sx[i];
		}
		if(ct2 > n / 2){
			for(int i = 1;i <= ct2;i++){
				int xw = b[i].x;
				sx[i] = jl[xw][1] - max(jl[xw][0], jl[xw][2]);
			}
			sort(sx + 1, sx + ct2 + 1);
			for(int i = 1;i <= ct2 - n / 2;i++) ans -= sx[i];
		}
		if(ct3 > n / 2){
			for(int i = 1;i <= ct3;i++){
				int xw = c[i].x;
				sx[i] = jl[xw][2] - max(jl[xw][1], jl[xw][0]);
			}
			sort(sx + 1, sx + ct3 + 1);
			for(int i = 1;i <= ct3 - n / 2;i++) ans -= sx[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
