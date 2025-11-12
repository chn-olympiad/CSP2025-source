#include<iostream>
#include<cstring>
#include<queue>
using namespace std;


int n, q;
int len[1000010];
char s1[1010][2010];
char s2[1010][2010];
char t1[1010];
char t2[1010];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s1[i] + 1);
		scanf("%s", s2[i] + 1);
		len[i] = strlen(s1[i] + 1);
	}
	
	for(int i = 1; i <= q; i++)
	{
		scanf("%s", t1 + 1);
		scanf("%s", t2 + 1);
		int slen = strlen(t1 + 1);
		int ans = 0;
		for(int j = 1; j <= n; j++)
		{
			for(int l = 1; l <= slen - len[j] + 1; l++)
			{
				bool flag = true;
				for(int k = 1; k < l; k++) flag &= (t1[k] == t2[k]);
				for(int k = l; k <= l + len[j] - 1; k++) flag &= (t1[k] == s1[j][k - l + 1] && t2[k] == s2[j][k - l + 1]);
				for(int k = l + len[j]; k <= slen; k++) flag &= (t1[k] == t2[k]);
				ans += flag;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
i tried but failed

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;


char s1[2500010];
char s2[2500010];

int tr1[2500010][26], tot1;
int tr2[2500010][26], tot2;

int fa1[2500010];
int fa2[2500010];

int f[2500010];
int ff[2500010];
int f2[2500010];
int siz[2500010];
int dfn[2500010], dfni;
int ans[200010];
int slen[2500010];

int n, q;

vector<int> G1[2500010];
vector<int> G2[2500010];

int jump[2500010][23];

void insert1()
{
	int len = strlen(s1 + 1);
	int p1 = 0;
	int p2 = 0;
	for(int i = 1; i <= len; i++)
	{
		int c1 = s1[i] - 'a';
		int c2 = s2[i] - 'a';
		if(!tr1[p1][c1]) tr1[p1][c1] = ++tot1;
		if(!tr2[p2][c2]) tr2[p2][c2] = ++tot2;
		p1 = tr1[p1][c1]; 
		p2 = tr2[p2][c2]; 
		slen[p2] = i;
	}
	f[p1] = p2;
}

struct node
{
	int p2, id, k;
};

vector<node> qry[2500010];

void insert2(int id)
{
	int len = strlen(s1 + 1);
	int p1 = 0;
	int p2 = 0;
	int dstart = 0;
	int dend = 0;
	
	for(int dstart = 1; dstart <= len && s1[dstart] == s2[dstart]; dstart++)
	for(int dend = len; dend >= 1 && s1[dend] == s2[dend]; dend--)
	
//	printf("%d\n", id);
	if(id == 100)
		printf("100\n"); 
	for(int i = 1; i <= len; i++)
	{
		int c1 = s1[i] - 'a';
		int c2 = s2[i] - 'a';
		if(!tr1[p1][c1]) tr1[p1][c1] = ++tot1;
		if(!tr2[p2][c2]) tr2[p2][c2] = ++tot2;
		p1 = tr1[p1][c1]; 
		p2 = tr2[p2][c2]; 
		
		if(i >= dend)
		{
			int dlen = i - dstart + 1;
			qry[p1].push_back({p2, id, 1});
			int t = p2;
			for(int j = 22; j >= 0; j--) if(slen[jump[t][j]] >= dlen) t = jump[t][j];
			t = jump[t][0];
			qry[p1].push_back({t, id, -1});
		}
	}
}

queue<int> que;

void build1()
{
	while(!que.empty()) que.pop();
	for(int i = 0; i < 26; i++) if(tr1[0][i]) fa1[tr1[0][i]] = 0, que.push(tr1[0][i]);
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		for(int i = 0; i < 26; i++)
		{
			if(tr1[u][i]) fa1[tr1[u][i]] = tr1[fa1[u]][i], que.push(tr1[u][i]);
			else tr1[u][i] = tr1[fa1[u]][i];
		}
	}
}

void build2()
{
	while(!que.empty()) que.pop();
	for(int i = 0; i < 26; i++) if(tr2[0][i]) fa2[tr2[0][i]] = 0, que.push(tr2[0][i]);
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		for(int i = 0; i < 26; i++)
		{
			if(tr2[u][i]) fa2[tr2[u][i]] = tr2[fa2[u]][i], que.push(tr2[u][i]);
			else tr2[u][i] = tr2[fa2[u]][i];
		}
	}
}

void dfs(int u)
{
	siz[u] = 1;
	dfn[u] = ++dfni;
	for(int v : G2[u])
	{
		dfs(v);
		siz[u] += siz[v];
	}
}

void addd(int x, int k)
{
	if(x <= 0) return; 
	for(; x <= dfni; x += x & -x) ff[x] += k;
}

void add(int l, int r, int k)
{
	addd(l, k);
	addd(r + 1, -k);
}

int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x) res += ff[x];
	return res;
}

void dfs3(int u)
{
	jump[u][0] = fa2[u];
	for(int i = 1; i <= 22; i++) jump[u][i] = jump[jump[u][i - 1]][i - 1];
	for(int v : G2[u]) dfs3(v);
}

void dfs2(int u)
{
//	printf("dfs %d\n", u);
	if(u && f[u])
		add(dfn[f[u]], dfn[f[u]] + siz[f[u]] - 1, 1);
	
	for(node pii : qry[u])
	{
		int res = query(dfn[pii.p2]);
		ans[pii.id] += pii.k * res;
	}
	for(int v : G2[u])
		dfs2(v);
	
	if(u && f[u]) add(dfn[f[u]], dfn[f[u]] + siz[f[u]] - 1, -1);
}

int main()
{
	freopen("replace3.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		insert1();
	}
	
	build1();
	build2(); 
	
	for(int i = 1; i <= tot1; i++) G1[fa1[i]].push_back(i);
	for(int i = 1; i <= tot2; i++) G2[fa2[i]].push_back(i);
	
	dfs3(0);
	
	for(int i = 1; i <= q; i++)
	{
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		insert2(i);
	}
	
	dfs(0);
	dfs2(0);
	
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}
*/ 
