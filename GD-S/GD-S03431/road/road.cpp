#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],b[10005],n,m,k,c[100000005],ans = 0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		a[min(u,v)][max(u,v)] = w;
	 } 
	 for(int i = 1;i <= k;i++)
	 {
	 	int c;
	 	cin >> c;
	 	for(int j = 1;j <= n;j++)
	 	{
	 		cin >> b[j]; 
		 }
		for(int j = 1;j <= n;j++)
	 	{
	 		for(int q = j + 1;q <= n;q++)
	 		{
	 			if(a[j][q] == 0) a[j][q] = b[i] + b[q] + c;
	 			else if(b[j] + b[q] + c < a[j][q]) a[j][q] = b[j] + b[q] + c;
			 }
		 }
	 }
	 int l = 1;
	 for(int i = 1;i <= n;i++)
	 {
	 	for(int j = i + 1;j <= n;j++)
	 	{
	 		if(a[i][j] != 0) c[l++] = a[i][j];
		 }
	 }
	 sort(c,c + l);
	 for(int i = 1;i <= n - 1;i++)
	 {
	 	ans += c[i];
	 }
	 cout << ans;
	return 0;
 } 
