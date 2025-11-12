#include<bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 5, M = 1e6 + 5;
long long m, n, k, T, mx[N], ans = 0x3f3f3f3f, w[20], fl[N][N], tem[20][N];
bool b[N], c[20];
void dfs(long long num/*走过的路*/, long long pos/*当前下标*/, long long sum/*耗费*/)
{
	if(num == 1)
	{
		ans = min(ans, sum);
		return;
	}
	for(long long i = pos; i <= n; i++){
		for(long long j = 1; j <= k; j++){
			if((!b[i])){
				if(!c[j]){
					b[i] = true;
					c[j] = true;
					dfs(num-1, i, sum + tem[j][pos] + tem[j][i] + w[i]);
					c[j] = false;
					if(fl[pos][i] != 0x3f){
						dfs(num-1, i, sum+fl[pos][i]);
					}	
					b[i] = false;
					return;
				}
				if(c[j])
				{	
					b[i] = true;
					dfs(num-1, i, sum + tem[k][i] + tem[j][pos]);
					if(fl[pos][i] != 0x3f)
					{
						dfs(num-1, i, sum+fl[pos][i]);
					}
					b[i] = false;
					return;
				}
			}
		}		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(fl, 0x3f, sizeof fl);
	memset(b, false, sizeof b);
	memset(c, false, sizeof c);
	memset(tem, 0x3f, sizeof tem);
	for(long long i = 1, x, y, q; i <= m; i++)
	{
		cin >> x >> y >> q;
		fl[x][y] = q;
		fl[y][x] = q;
	}
	for(long long i = 1; i <= k; i++)
	{
		cin >> w[i];
		for(long long j = 1; j <= n; j++)
		{
			cin >> tem[i][j];
		}
	}
	dfs(n, 1, 0);
	cout << ans;
	return 0;
}
