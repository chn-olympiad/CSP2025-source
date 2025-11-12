#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;
const long long INF = 0x7f7f7f7f7f7f;

int n , m , k;

long long c[MAXN];

long long al[15][MAXN];

struct Line{
	int u , v;
	long long w;
}l[MAXM] , L[MAXM] , LL[MAXM];

int tot;

bool cmp(Line a , Line b)
{
	return a.w < b.w;
}

int fa[MAXN];

int find_set(int x)
{
	if(fa[x] != x)fa[x] = find_set(fa[x]);
	return fa[x];
}

int u , v , w;

signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	n = read();
	m = read();
	k = read();
	
//	cout << n << " " << m << " " << k << endl;
	
	for(int i = 1;i <= n;i++)fa[i] = i;
	
	for(int i = 1;i <= m;i++)
	{
		l[i].u = read();
		l[i].v = read();
		l[i].w = read();
	}
	
	
	
	sort(l + 1 , l + 1 + m , cmp);
	
//	cout << 1 << endl;
	
	long long sum = 0;
	
	for(int i = 1;i <= m;i++)
	{
//		cout << i << endl;
//		cout << l[i].u << " " <<  
		int x = find_set(l[i].u);
		int y = find_set(l[i].v);
		if(x != y)
		{
			fa[x] = y;
			sum += l[i].w;
			L[++tot] = l[i];
		}
	}
	
//	cout << sum << endl;

	int ol = 0;
	
	for(int i = 1;i <= k;i++)
	{
		c[i] = read();
		if(c[i])ol = 1;
		for(int j = 1;j <= n;j++)
		{
			al[i][j] = read();
			if(al[i][j])ol = 1;
		}
	}
	
	if(!ol)
	{
		printf("0\n");
		return 0;
	}
	
	long long ans = INF;
	
	for(int i = 0;i < (1 << k);i++)
	{
		long long res = 0;
		int num = tot;
		for(int j = 1;j <= n + k;j++)fa[j] = j;
		for(int j = 1;j <= tot;j++)LL[j] = L[j];
		for(int j = 1;j <= k;j++)
		{
			if((1 <<(j - 1)) & i)
			{
				res += c[j];
				for(int v = 1;v <= n;v++)
				{
					LL[++num].u = j + n;
					LL[num].v = v;
					LL[num].w = al[j][v];
						
				} 
			}
		}
		sort(LL + 1 , LL + 1 + num , cmp);
		for(int i = 1;i <= num;i++)
		{
			int x = find_set(LL[i].u);
			int y = find_set(LL[i].v);
			
			if(x != y)
			{
				fa[x] = y;
				res += LL[i].w;
			}
		}

//		cout << res << endl;
		ans = min(ans , res);
	}
	
	printf("%lld\n" , ans);
	
	return 0;
}

/*

in:

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

out:

13

*/ 