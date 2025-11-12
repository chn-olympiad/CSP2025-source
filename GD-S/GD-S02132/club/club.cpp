#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x = 0, f = 1; char ch = getchar();while(ch > '9' or ch < '0'){if(ch == '-'){f = -1;}ch=getchar();}while(ch >= '0' and ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}return x * f;}
inline void write(int x){if(x < 0){putchar('-');x = -x;}if(x >= 10){write(x/10);}putchar(x % 10 + '0');}
#define pb emplace_back
#define put() putchar(' ')
#define endl puts("")
const int MAX = 1e5 + 10;

struct node{
	int a, b, c;
}; node a[MAX];

bool cmp(node x, node y){
	return max({x.a, x.b, x.c}) > max({y.a, y.b, y.c});
}

void solve(){
	int n = read();
	for(int i = 1; i <= n; i++){
		a[i].a = read(), a[i].b = read(), a[i].c = read();
	}
	sort(a + 1, a + n + 1, cmp);
	int cnt = 0, cnt2 = 0, cnt3 = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i].a >= a[i].b and a[i].a >= a[i].c){
			cnt++;
			ans += a[i].a;
		}
		else if(a[i].b >= a[i].a and a[i].b >= a[i].c){
			cnt2++;
			ans += a[i].b;
		}else{
			cnt3++;
			ans += a[i].c;
		}
	}
	if(cnt <= n / 2 and cnt2 <= n / 2 and cnt3 <= n / 2){
		write(ans), endl;
		return ;
	}
	if(cnt > n / 2){
		priority_queue <int> q;
		for(int i = 1; i <= n; i++){
			if(a[i].a >= a[i].b and a[i].a >= a[i].c){
				q.push(max(a[i].b, a[i].c) - a[i].a);
			}
			else if(a[i].b >= a[i].a and a[i].b >= a[i].c){
			}else{
			}
		}
		while(cnt > n / 2){
			cnt--;
			ans += q.top();
			q.pop();
		}
	}else if(cnt2 > n / 2){
		priority_queue <int> q;
		for(int i = 1; i <= n; i++){
			if(a[i].a >= a[i].b and a[i].a >= a[i].c){
			}
			else if(a[i].b >= a[i].a and a[i].b >= a[i].c){
				q.push(max(a[i].a, a[i].c) - a[i].b);
			}else{
			}
		}
		while(cnt2 > n / 2){
			cnt2--;
			ans += q.top();
			q.pop();
		}
	}else{
		priority_queue <int> q;
		for(int i = 1; i <= n; i++){
			if(a[i].a >= a[i].b and a[i].a >= a[i].c){
			}
			else if(a[i].b >= a[i].a and a[i].b >= a[i].c){
			}else{
				q.push(max(a[i].a, a[i].b) - a[i].c);
			}
		}
		while(cnt3 > n / 2){
			cnt3--;
			ans += q.top();
			q.pop();
		}
	}
	write(ans), endl;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while(t--)	solve();
	return 0;
}