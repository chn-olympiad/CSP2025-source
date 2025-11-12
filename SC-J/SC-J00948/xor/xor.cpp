#include <bits/stdc++.h>
using namespace std;
int a[500050], n, k, cnt;
int xo(int x, int y)
{
	int m = x & y;
	int s = (x - m) | (y - m);
	return s;
}
bool vis[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
    for(int i = 1;i <= n;i ++)                                                                                                                                                                                            
	    cin >> a[i];
	for(int i = 1;i <= n;i ++)
	{
		int ans = 0;
	    for(int j = i;j <= n;j ++)
	    {
	    	if(vis[i] == 1)
	    	    break;
	       	ans = xo(ans, a[j]);
	       	if(ans == k)
	       	{
	       		for(int k = i;k <= j;k ++)
	       		    vis[k] = 1;
	       		cnt ++;
	       		i = j;
	       	}
		}
	}
	cout << cnt;
	return 0;
}