#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;
char s[N], t[N], S[N];
int ch[N][26], fail[N], sum[N], tot;
queue<int> q;
void ins(int m)
{
	int i, p = 0;
	for(i = 0; i < m; i++)
	{
		if(!ch[p][S[i] - 'a'])
			ch[p][S[i] - 'a'] = ++tot;
		p = ch[p][S[i] - 'a'];
	}
	sum[p]++;
}
void build()
{
	int i, x;
	for(i = 0; i < 26; i++)
		if(ch[0][i])
			q.push(ch[0][i]);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		sum[x] += sum[fail[x]];
		for(i = 0; i < 26; i++)
			if(ch[x][i])
			{
				fail[ch[x][i]] = ch[fail[x]][i];
				q.push(ch[x][i]);
			}
			else
				ch[x][i] = ch[fail[x]][i];
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, i, j, m, l, r, u, v;
	long long ans;
	scanf("%d%d", &n, &q);
	for(i = 1; i <= n; i++)
	{
		scanf("%s%s", s, t);
		m = strlen(s);
		for(j = 0; j < m; j++)
		{
			S[2 * j] = s[j];
			S[2 * j + 1] = t[j];
		}
		ins(2 * m);
	}
	build();
	while(q--)
	{
		scanf("%s%s", s, t);
		m = strlen(s);
		if(m != strlen(t))
		{
			printf("0\n");
			continue;
		}
		for(j = 0; j < m; j++)
		{
			S[2 * j] = s[j];
			S[2 * j + 1] = t[j];
		}
		l = 0;
		while(l < 2 * m && S[l] == S[l + 1])
			l += 2;
		r = 2 * m - 1;
		while(r && S[r] == S[r - 1])
			r -= 2;
		ans = 0;
		u = v = 0;
		for(j = 0; j <= l; j++)
			u = ch[u][S[j] - 'a'];
		for(j = l + 1; j < 2 * m; j++)
		{
			u = ch[u][S[j] - 'a'];
			v = ch[v][S[j] - 'a'];
			if(j >= r && (j & 1))
				ans += sum[u] - sum[v];
		}
		printf("%lld\n", ans);
	}
	return 0;
}