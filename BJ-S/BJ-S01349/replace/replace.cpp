#include <bits/stdc++.h>
using namespace std;
vector<int> vec[5000010]; int fa[24][5000010],len[5000010],sum[5000010];
char s[5000010],t[5000010],op[5000010]; int ss,ts,ops;
struct trie {
	int ch[5000010][26],fail[5000010],cnt = 0;
	void ins() {
		int cur = 0; for(int i = 0; i < ops; i++) {
			int& c = ch[cur][op[i]-'a'];
			if(!c) c = ++cnt,len[c] = len[cur]+1; cur = c;
		} sum[cur]++;
	}
	void build() {
		queue<int> q;
		for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
		while(q.size()) {
			int cur = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				int &c = ch[cur][i],f = ch[fail[cur]][i];
				if(c) {fail[c] = f; q.push(c);}
				else c = f;
			}
		}
		for(int i = 1; i <= cnt; i++) vec[fail[i]].push_back(i);
	}
}tt;
void dfs(int now,int pa) {
	fa[0][now] = pa; sum[now] += sum[pa];
	for(int i = 1; i <= 23; i++) fa[i][now] = fa[i-1][fa[i-1][now]];
	for(auto v:vec[now]) dfs(v,now);
}
int n,q;
int main() {
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	scanf("%d%d",&n,&q); for(int i = 1; i <= n; i++) {
		scanf("%s%s",s,t); ss = strlen(s); ts = strlen(t); ops = 0;
		for(int i = 0; i < ss; i++) {
			op[ops++] = s[i]; op[ops++] = t[i];
		} tt.ins();
	} tt.build(); dfs(0,0);
	while(q--) {
		scanf("%s%s",s,t); ss = strlen(s); ts = strlen(t);
		if(ss != ts) {puts("0"); continue;}
		int l = ss+1,r = 0;
		for(int i = 0; i < ss; i++) if(s[i] != t[i]) r = i;
		for(int i = ss-1; i >= 0; i--) if(s[i] != t[i]) l = i;
		int cur = 0; long long ans = 0; for(int i = 0; i < ss; i++) {
			cur = tt.ch[cur][s[i]-'a']; cur = tt.ch[cur][t[i]-'a'];
			if(i < r) continue; int x = cur; ans += sum[cur];
			for(int k = 23; k >= 0; k--) {
				if(2*i-2*l+2 <= len[fa[k][x]]) x = fa[k][x];
			} if(2*i-2*l+2 <= len[x]) x = fa[0][x];
			ans -= sum[x];
			//printf("%d %lld %lld\n",i,sum[cur],sum[fa[0][x]]);
		} printf("%lld\n",ans);
	}
	return 0;
}
