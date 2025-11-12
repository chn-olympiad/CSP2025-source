#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int l;
int r;
int cnt = 0;
int maxn = -1e8;

void dfs(int l,int k,int &maxn)
{
	if(l == n) return ;
	int cnt = 0;
	cnt = a[l];
	for(int i = l;i < n;i++)
	{
		cnt = cnt xor a[i+1];
		if(cnt == k)
		{
			int temp = i-l+1;
			if(temp > maxn) maxn = temp;
			dfs(++l,k,maxn);
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == k)
		{
			maxn = 1;
		}
	}
	dfs(1,k,maxn);
	cout << maxn; 
	return 0;
}