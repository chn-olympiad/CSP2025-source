#include<bits/stdc++.h>
using namespace std;
int tr[1005][1005];
int c[105];
int r[105][1005];
int ut[100005];
int vt[100005];
int read()
{
	char ch = getchar();
	while(ch == '\n' || ch == ' ') ch = getchar();
	int f = 1,x = 0;
	while(ch == '-') f = -f,ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch - '0'),ch = getchar();
	return f * x; 
}
int main()
{
	freopen("road.in","r",stdin);
	
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	memset(tr,0x3f,sizeof(tr));
	for(int i = 1;i <= n;i++) tr[i][i] = 0;
	for(int i = 1;i <= m;i++)
	{
		int u,v,cost;
		u = read();
		v = read();
		cost = read(); 
		tr[u][v] = cost;
		tr[v][u] = cost;
		ut[i] = u;
		vt[i] = v;
	}
	int featureA = 0;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
			cin >> r[i][j];
		featureA += c[i];
	}
	if(!featureA)
	{
		for(int i = 1;i <= k;i++)
			for(int j = 1;j <= n;j++)
				for(int k = j + 1;k <= n;k++)
					tr[j][k] = tr[k][j] = min(tr[j][k],r[i][j] + r[i][k]);
		map <int,int> p[1005];
		for(int l = 1;l <= n;l++)
			for(int i = 1;i <= m;i++)
				if(tr[ut[i]][vt[i]] > tr[ut[i]][l] + tr[l][vt[i]]) p[ut[i]][vt[i]] = false,p[ut[i]][l] = p[l][vt[i]] = true;
				else p[ut[i]][vt[i]] = true,p[ut[i]][l] = p[k][vt[i]] = false;
		
		int ans = 0;

		for(int i = 1;i <= m;i++)
		{
			if(p[ut[i]][vt[i]]) ans += tr[ut[i]][vt[i]];
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
