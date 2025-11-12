#include<bits/stdc++.h>
#define int long long
#define pai pair<int,int>
using namespace std;
const int N = 1e5 + 10;
int T;
int n;
struct node {
	int a, b, c;
}s[N];
priority_queue<pai> ab, ac, ba, bc, ca, cb;
priority_queue<int,vector<int>, greater<int> > A, B, C;
set<int> a, b, c;
int lena, lenb, lenc, ans;
void moveab() {
	int u = ab.top().second;
	int w = ab.top().first;
	ab.pop();
	a.erase(u);
	ans += w;
	b.insert(u);
	ba.push({s[u].a - s[u].b,u});
	bc.push({s[u].c - s[u].b,u});
	lena --;
	lenb ++;
}
void moveac() {
	int u = ac.top().second;
	int w = ac.top().first;
	ac.pop();
	a.erase(u);
	ans += w;
	c.insert(u);
	ca.push({s[u].a - s[u].c,u});
	cb.push({s[u].b - s[u].c,u});
	lena--;
	lenc++;
}
void moveba() {
	int u = ba.top().second;
	int w = ba.top().first;
	ba.pop();
	b.erase(u);
	ans += w;
	a.insert(u);
	ab.push({s[u].b - s[u].a,u});
	ac.push({s[u].c - s[u].a,u});
	lenb--;
	lena++;
}
void movebc(){
	int u = bc.top().second;
	int w = bc.top().first;
	bc.pop();
	b.erase(u);
	ans += w;
	c.insert(u);
	ca.push({s[u].a - s[u].c,u});
	cb.push({s[u].b - s[u].c,u});
	lenb--;
	lenc++;
}
void moveca() {
	while(!ca.empty() && c.find(ca.top().second) == c.end()) ca.pop();
	while(!cb.empty() && c.find(cb.top().second) == c.end()) cb.pop();
	int u = ca.top().second;
	int w = ca.top().first;
	ca.pop();
	c.erase(u);
	ans += w;
	a.insert(u);
	ab.push({s[u].b - s[u].a,u});
	ac.push({s[u].c - s[u].a,u});
	lenc--;
	lena++;
}
void movecb() {
	int u = cb.top().second;
	int w = cb.top().first;
	cb.pop();
	c.erase(u);
	ans += w;
	b.insert(u);
	ba.push({s[u].a - s[u].b,u});
	bc.push({s[u].c - s[u].b,u});
	lenc--;
	lenb++;
}
signed main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin >> T;
	while(T --) {
		a.clear();
		b.clear();
		c.clear();
		while(!ab.empty()) ab.pop();
		while(!ac.empty()) ac.pop();
		while(!ba.empty()) ba.pop();
		while(!bc.empty()) bc.pop();
		while(!ca.empty()) ca.pop();
		while(!cb.empty()) cb.pop();
		cin >> n;
		lena = n;
		lenb = 0;
		lenc = 0;
		ans = 0;
		while(!A.empty()) A.pop();
		while(!B.empty()) B.pop();
		while(!C.empty()) C.pop();
		for(int i = 1;i <= n;i ++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			a.insert(i);
			ab.push({s[i].b - s[i].a, i});
			ac.push({s[i].c - s[i].a, i});
			ans += s[i].a;
			A.push(s[i].a);
		}
		while(max(lena, max(lenb, lenc)) > n / 2) {
			if(lena > n / 2) {
				while(!ab.empty() && a.find(ab.top().second) == a.end()) ab.pop();
				while(!ac.empty() && a.find(ac.top().second) == a.end()) ac.pop();
				if(ab.top().first > ac.top().first && lenb + 1 <= n / 2) {
					moveab();
				} else if(lenc + 1 <= n / 2) {
					moveac();
				}
			} else if(lenb > n / 2) {
				while(!ba.empty() && b.find(ba.top().second) == b.end()) ba.pop();
				while(!bc.empty() && b.find(bc.top().second) == b.end()) bc.pop();
				if(ba.top().first > bc.top().first && lena + 1 <= n / 2) {
					moveba();
				} else if(lenc + 1 <= n / 2){
					movebc();
				}
			} else if(lenc > n / 2) {
				if(ca.top().first > cb.top().first && lena + 1 <= n / 2) {
					moveca();	
				} else if(lenb + 1 <= n / 2){
					movecb();
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}










