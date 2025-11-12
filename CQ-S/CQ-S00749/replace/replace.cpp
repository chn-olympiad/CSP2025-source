#include <bits/stdc++.h>
#define maxn 200005
#define maxn2 10000005
#define p 19491001
using namespace std;
int n,m,q,cnt = 1,l,r,ans;
int to[maxn2][26],fail[maxn2],dep[maxn2],num[maxn2];
queue<int> qe;
string a,b,s,t;
void init(){
	for (int i = 0;i < 26;i++) to[0][i] = 1;
	qe.push(1);
	while (!qe.empty()){
		int x = qe.front();qe.pop();
		for (int i = 0;i < 26;i++){
			if (to[x][i]) dep[to[x][i]] = dep[x]+1,fail[to[x][i]] = to[fail[x]][i],qe.push(to[x][i]);
			else to[x][i] = to[fail[x]][i];
		}
	}
}
signed main(){
	//freopen("D:\\replace\\replace3.in","r",stdin);
	//freopen("D:\\replace\\replace.out","w",stdout);
	#ifndef LOCAL
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 1,now;i <= n;i++){
		cin >> a >> b,m = a.size(),now = 1;
		for (int j = 0;j < m;j++){
			if (!to[now][a[j]-'a']) now = to[now][a[j]-'a'] = ++cnt;
			else now = to[now][a[j]-'a'];
			if (!to[now][b[j]-'a']) now = to[now][b[j]-'a'] = ++cnt;
			else now = to[now][b[j]-'a'];
		}
		num[now]++;
	}
	init();
	while (q--){
		cin >> s >> t,m = s.size(),l = -1,r = -1,ans = 0;
		for (int i = 0;i < m;i++){
			if (s[i] != t[i]){
				if (l == -1) l = i;
				r = i;
			}
		}
		//cout << l << " " << r << "\n";
		for (int i = 0,now = 1,x;i < m;i++){
			now = to[now][s[i]-'a'],now = to[now][t[i]-'a'];
			x = now;
			if (i < r) continue;
			while (x && i-(dep[x]/2)+1 <= l){
				if (dep[x]%2 == 0) ans += num[x];
				x = fail[x];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
