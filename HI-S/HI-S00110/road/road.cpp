#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 1;
const int MAX_M = 1e6 + 1;
const int MAX_K = 10 + 1;

struct conn
{
	int u, v, w;
};

struct town
{
	int c;
	int a[MAX_N];
};

int n, m, k;
conn conns[MAX_M];
town towns[MAX_K];

void read()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 1; i <= m; i ++) 
	{
		cin >> conns[i].u >> conns[i].v >> conns[i].w;
	}
	
	for (int i = 1; i <= k; i ++) 
	{
		cin >> towns[i].c;
		for (int j = 1; j <= n; j ++) 
		{
			cin >> towns[i].a[j];
		}
	}
}

class wbc
{
private:
	int pare[MAX_M + MAX_K - 1];
public:
	wbc()
	{
		for (int i = 0; i < MAX_M + MAX_K - 1; i ++)
		{
			pare[i] = i;
		}
	}
	
	int find_root(int target)
	{
		int current = target;
		while (current != pare[current])
		{
			current = pare[current];
		}
		
		return current;
	}
	
	bool check(int a, int b)
	{
		return find_root(a) != find_root(b);
	}
	
	void unite(int root, int detaching_node)
	{
		pare[detaching_node] = find_root(root);
	}
};

int main()
{
	freopen("read.in", "r", stdin);
	freopen("read.out", "w", stdout);
	
	read();
	return 0;
}


