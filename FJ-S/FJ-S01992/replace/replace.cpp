#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int x = 0, ff = 1;
	char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar(); 
	if(c == '-') c = getchar(), ff = -1;
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * ff;
}
const int N = 2.1e5, M = 5.1e6;
struct node{
	int son[26], fail, len, op, cnt, now, sum;
};
int debug = 0;
node f[M];
int n, Q, sz;
char s[2][M];
int newnode(int LEN, int OP){
	f[++sz].len = LEN;
	f[sz].op = OP;
	f[sz].now = sz;
	return sz;
}
int q[M];
void getfail(){
	int l = 1, r = 0;
	for(int i = 0; i < 26; ++i)
		if(f[0].son[i]){
			f[ f[0].son[i] ].fail = 0;
			q[++r] = f[0].son[i];
		}
	while(l <= r){
		int x = q[l++];
		for(int i = 0; i < 26; ++i)
			if(f[x].son[i]){
				f[ f[x].son[i] ].fail = f[f[x].fail].son[i];
				q[++r] = f[x].son[i];
			}
			else
				f[x].son[i] = f[f[x].fail].son[i];
	}
}
int L[N], R[N], ed[N], NOW[M];
char t[2][M];
LL ans[N];
bool cmp(const int& X, const int& Y){
	return ed[X] - ed[X - 1] - L[X] > ed[Y] - ed[Y - 1] - L[Y];
}
void jmp(int x, int len){
	int now = f[x].now;
	if(f[f[now].fail].len >= len){
		jmp(f[now].fail, len);
		f[x].sum += f[f[now].fail].sum;
		f[x].now = f[f[now].fail].now;
	}
}
int st[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(); Q = read();
	for(int i = 1; i <= n; ++i){
		scanf("%s%s", s[0] + 1, s[1] + 1);
		int now = 0, len = strlen(s[0] + 1);
		for(int j = 1; j <= len; ++j){
			int x = s[0][j] - 'a';
			if(!f[now].son[x])
				f[now].son[x] = newnode(j, 0);
			now = f[now].son[x];
			x = s[1][j] - 'a';
			if(!f[now].son[x])
				f[now].son[x] = newnode(j, 1);
			now = f[now].son[x];
			if(debug)
				cerr << i << ' ' << j << ' ' << now << endl;
		}
		f[now].cnt++;
		f[now].sum++;
	}
	getfail();
	if(debug)
		for(int i = 1; i <= sz; ++i)
			printf("fail[%d] = %d\n", i, f[i].fail);
	int maxlen = 0;
	for(int i = 1, ST = 0; i <= Q; ++i){
		scanf("%s%s", t[0] + ST + 1, t[1] + ST + 1);
		int len = strlen(t[0] + ST + 1), now = 0;
		for(int j = 1; j <= len; ++j){
			if(t[0][j + ST] != t[1][j + ST]){
				if(!L[i]) L[i] = j;
				R[i] = j;
			}
			int c = t[0][j + ST] - 'a';
			now = f[now].son[c];
			c = t[1][j + ST] - 'a';
			now = f[now].son[c];
			NOW[j + ST] = now;
			if(debug)
				printf("NOW[%d][%d] = %d\n", i, j, now);
		}
		ST = ed[i] = ST + len;
		q[i] = i;
		maxlen = max(maxlen, len - L[i] + 1);
		if(debug)
			printf("L[%d] = %d  R[%d] = %d\n", i, L[i], i, R[i]);
	}
	sort(q + 1, q + Q + 1, cmp);
	for(int i = maxlen, p = 1, top = 0; i; --i){
		while(p <= Q && ed[q[p]] - ed[q[p] - 1] - L[q[p]] + 1 >= i) st[++top] = q[p++];
		if(debug)
			cout << "maxlen = " << i << " : " << p << ' ' << top << endl;
		for(int j = 1; j <= top; ++j){
			int x = st[j], y = ed[x] - (ed[x] - ed[x - 1] - L[x] + 1) + i;
			if(debug)
				cout << "x : " << x << "  y : " << y << endl;
			jmp(NOW[y], i);
			if(f[NOW[y]].len >= i)
				ans[x] += f[NOW[y]].sum;
			if(debug)
				cerr << "new_ans : " << f[NOW[y]].sum << endl;
//			cerr << now << f[now].len << ' ' << i << endl;

			if(debug){
				int now = NOW[y];
				while(f[now].len >= i){
					cout << now << ' ';
					now = f[now].fail;
				}
				cout << endl;
			}
			if(i == R[x] - L[x] + 1){
				swap(st[j], st[top]);
				--top, --j;
			}
		}
	}
	for(int i = 1; i <= Q; ++i)
		cout << ans[i] << '\n';
	return 0;
} 
