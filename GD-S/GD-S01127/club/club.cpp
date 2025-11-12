#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N][5];
void read(int &x){
	x = 0;
	int sign = 1;
	char c = getchar();
	while (!isdigit(c)){
		if(c == '-') sign = -1;
		c = getchar();
	} 
	while (isdigit(c)){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= sign;
}
struct Node{
	int id, x, d;
	bool operator< (const Node & w) const{
		return x > w.x;
	}
};
Node b[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	read(T);
	while (T -- ){
		int n;
		read(n);
		for (int i = 1; i <= n; i ++ ) read(a[i][1]), read(a[i][2]), read(a[i][3]), b[i] = {i, a[i][1], 0};
		priority_queue<Node> q1, q2, q3;
		int res = 0;
		for (int i = 1; i <= n; i ++ ){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) q1.push({i, a[i][1] - max(a[i][2], a[i][3])}), res += a[i][1];
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) q2.push({i, a[i][2] - max(a[i][1], a[i][3])}), res += a[i][2];
			else q3.push({i, a[i][3] - max(a[i][1], a[i][2])}), res += a[i][3];
		}
		if(q1.size() > n / 2){
			while (q1.size() > n / 2){
				Node t = q1.top();
				q1.pop();
				int i = t.id;
				res -= a[i][1];
				if(a[i][2] > a[i][3]) q2.push({i, a[i][2]}), res += a[i][2];
				else q3.push({i, a[i][3]}), res += a[i][3];
			}
		}
		if(q2.size() > n / 2){
			while (q2.size() > n / 2){
				Node t = q2.top();
				q2.pop();
				int i = t.id;
				res -= a[i][2];
				if(a[i][1] > a[i][3]) q1.push({i, a[i][1]}), res += a[i][1];
				else q3.push({i, a[i][3]}), res += a[i][3];
			}
		}
		if(q3.size() > n / 2){
			while (q3.size() > n / 2){
				Node t = q3.top();
				q3.pop();
				int i = t.id;
				res -= a[i][3];
				if(a[i][1] > a[i][2]) q1.push({i, a[i][1]}), res += a[i][1];
				else q2.push({i, a[i][2]}), res += a[i][2];
			}
		}
//		cout << q1.size() << ' ' << q2.size() << ' ' << q3.size() << '\n';
//		cout << q3.top().id << '\n';
		cout << res << '\n';
	}
	return 0;
} 
