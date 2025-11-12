#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
bool vis[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","in",stdin);
	freopen("seat.out","out",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int p = a[1];
	sort(a+1,a+1+n*m,cmp);
	int h = 1,l = 1,ans = 1;
	int ok = 1;
	while(1)
	{
		if(a[ans] == p)
		{
			cout << l << " " << h;
			return 0;
		}
		else
		{
			if(h+ok > n || h+ok < 1)
			{
				l++;
				ok = 0-ok;
			}
			else
			{
				h+=ok;
			}
		}
		ans++;
	}
	return 0;	
}
