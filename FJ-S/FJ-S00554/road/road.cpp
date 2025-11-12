#include<iostream>
using namespace std;

int n,m,k;
int ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	int r[m + 1][3];
	int vil[k+1];
	int vill[n+1][k+1];
	int u,v,w,iu = 0,iv = 0;
	for(int i = 1;i <= m;i ++ )
	{
		cin >> u >> v >> w;
		r[i][0] = u;r[i][1] = v;r[i][2] = w;
	}
	for(int i = 1;i <= k;i ++ )
	{
		cin >> w;
		vil[i] = w;
		for(int j = 1;j <= n;j ++ )
		{
			cin >> w;
			vill[j][i] = w;
		}
	}
	
	int ww;
	int wmin = 1000000000;
	for(int i = 1;i <= m;i ++ )
	{
		for(int j = 1;j <= k;j ++ )
		{
			ww = vill[r[i][0]][j] + vill[r[i][1]][j] + vil[j];
			if(ww < wmin) wmin = ww;
		}
		if(r[i][2] < wmin) wmin = r[i][2];
		
		ans += wmin;
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
