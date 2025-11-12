#include<bits/stdc++.h>
using namespace std;

struct Node{
	int a, b, c;
}s[100005];

int sol(Node x, int op){
	int a = x.a, b = x.b, c = x.c;
	if(a > b)swap(a, b);
	if(b > c)swap(b, c);
	if(a > b)swap(a, b);
	if(op==0)return c - b;
	else return b - a;
}

bool cmp(Node x, Node y){
	int t1 = sol(x, 0), t2 = sol(y, 0);
	if(t1 != t2){
		return t1 > t2;
	}
	t1 = sol(x, 1), sol(y, 1);
	if(t1 != t2){
		return t1 > t2;
	}
	return max(x.a, max(x.b, x.c)) > max(y.a, max(y.b, y.c));
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		memset(s, 0, sizeof(s));
		long long sum = 0;
		int n, cnt[3] = {0, 0, 0};
		cin >> n;
		for(int i=1; i<=n; i++) cin >> s[i].a >> s[i].b >> s[i].c;
		sort(s+1, s+1+n, cmp);
		for(int i=1; i<=n; i++){
			int a = s[i].a, b = s[i].b, c = s[i].c;
			int q = 0, w = 1, e = 2;
			if(a < b) swap(a, b), swap(q, w);
			if(b < c) swap(b, c), swap(w, e);
			if(a < b) swap(a, b), swap(q, w);
			if(a == c){
				if(cnt[q] > cnt[w])swap(q, w), swap(a, b);
				if(cnt[w] > cnt[e])swap(w, e), swap(b, c);
				if(cnt[q] > cnt[w])swap(q, w), swap(a, b);
				
			}else if(a == b){
				if(cnt[q] > cnt[w])swap(q, w), swap(a, b);
			}else if(b == c){
				if(cnt[w] > cnt[e])swap(w, e), swap(b, c);
			}
			if(cnt[q] < n / 2)sum += a, cnt[q]++;
			else sum += b, cnt[w]++;
		}
		cout << sum << "\n";
	}
	return 0;
}
