#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(!('0' <= ch && ch <= '9')) {
		if(ch == '-')
			f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 1e5 + 5;

struct node {
	int val , type , id;
	node(int a = 0 , int b = 0 , int c = 0) : val(a) , type(b) , id(c) {};
	bool operator < (node b) const {
		return val < b.val;
	}
} ;
priority_queue<node> member;
unordered_map<int , bool> ma;
int n = 0 , t = 0 , sum[4] , ans = 0 , maxx = -100;
int m1[N][4];

void init() {
	ans = 0 , n = 0;
	memset(sum , 0 , sizeof(sum));
	while(!member.empty())
		member.pop();
	ma.clear();
	memset(m1 , 0 , sizeof(m1));
	n = 0 , maxx = -100;
}

void dfs(int u , int value , int s1 , int s2 , int s3) {
	if(u >= n + 1) {
		maxx = max(maxx , value);
		return;
	}
	if(s1 + 1 <= n/2)
		dfs(u+1 , value + m1[u][1] , s1+1 , s2 , s3);
	if(s2 + 1 <= n/2)
		dfs(u+1 , value + m1[u][2] , s1 , s2+1 , s3);
	if(s3 + 1 <= n/2)
		dfs(u+1 , value + m1[u][3] , s1 , s2 , s3+1);
}

void solve() {
	init();
	n = read();
	if(n <= 26) {
		for(int i = 1 ; i <= n ; i++) { m1[i][1] = read(); m1[i][2] = read(); m1[i][3] = read(); }
		dfs(1 , 0 , 0 , 0 , 0);
		cout << maxx << "\n" ;
	} else {
		for(int i = 1 ; i <= n ; i++) {
			int a = read() , b = read() , c = read();
			member.push(node(a , 1 , i));
			member.push(node(b , 2 , i));
			member.push(node(c , 3 , i));
		}
		while(!member.empty()) {
			node temp = member.top();member.pop();
			ma[temp.id] = 1;
			sum[temp.type]++;
			ans += temp.val;
			while(!member.empty() && (sum[member.top().type] >= n/2 || ma[member.top().id])) member.pop();
		}
		cout << ans << "\n" ;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t = read();
	while(t--) { solve(); }

	return 0;
}
