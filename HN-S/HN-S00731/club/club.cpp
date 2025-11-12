#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][4], n;
struct node{
	int i, xd, k;
	node(int ii, int xx, int kk): i(ii), xd(xx), k(kk) {};
	bool operator < (const node &s1) const {
		return s1.xd < xd;
	}
};
priority_queue<node>q1, q2, q3;
void init(){
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	while(!q3.empty())q3.pop();
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin >> t;while(t--){
		init();
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
			int pa = a[i][1], pb = a[i][2], pc = a[i][3];
			if(pa >= pb && pb >= pc){
				q1.push(node(i, pa - pb, 2));
			}else if(pa >= pc && pc >= pb){
				q1.push(node(i, pa - pc, 3));
			}else if(pb >= pa && pa >= pc){
				q2.push(node(i, pb - pa, 1));
			}else if(pb >= pc && pc >= pa){
				q2.push(node(i, pb - pc, 3));
			}else if(pc >= pa && pa >= pb){
				q3.push(node(i, pc - pa, 1));
			}else{
				q3.push(node(i, pc - pb, 2));
			}
			ans += max(max(pa, pb), pc);
		}
		while(q1.size() > n / 2){
			node tmp = q1.top();
			q1.pop();
			ans -= tmp.xd;
		}
		while(q2.size() > n / 2){
			node tmp = q2.top();
			q2.pop();
			ans -= tmp.xd;
		}
		while(q3.size() > n / 2){
			node tmp = q3.top();
			q3.pop();
			ans -= tmp.xd;
		}
		cout << ans << "\n";
	}
	return 0;
}
