#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pr;
int read() {
	int x=0,f=1;char chr=getchar();
	while(chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
}
const int N = 1e5 + 10;
int T,n;
int ans;
int a[N][3];
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		//cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
	}
}
struct cmp {
	bool operator()(pr a,pr b) {
		return a.second < b.second;
	}
};
void calc() {
	ans = 0;
	priority_queue<pr,vector<pr>,cmp> q1,q2,q3;
	for (int i = 1; i <= n; i++) {
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
			q1.push({i,max(a[i][1],a[i][2]) - a[i][0]});
			ans += a[i][0];
		}
		else if (a[i][1] >= a[i][2]) {
			q2.push({i,max(a[i][0],a[i][2]) - a[i][1]});
			ans += a[i][1];
		}
		else {
			q3.push({i,max(a[i][0],a[i][1]) - a[i][2]});
			ans += a[i][2];
		}
	}
	while (q1.size() > n / 2) {
		ans += q1.top().second;
		q1.pop();
	}
	while (q2.size() > n / 2) {
		ans += q2.top().second;
		q2.pop();
	}
	while (q3.size() > n / 2) {
		ans += q3.top().second;
		q3.pop();
	}
	cout << ans << "\n";
}
void solve() {
	init();
	calc();
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
