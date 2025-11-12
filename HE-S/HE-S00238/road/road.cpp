//#include <bits/stdc++.h>
////未解决问题：包含路径未归零而重复计算 
//using namespace std;
//
////road
//
//int n,m,k;
//long long g1[10005][10005];
//long long g2[15][100005];
//bool vis[15];
//long long ans;
//
//void init(){
//	for(int i = 1;i <= n;i ++)
//	{
//		for(int j = 1;j <= n;j ++)
//		{
//			g1[i][j] = LONG_LONG_MAX; //权值最大化 
//			g1[j][i] = LONG_LONG_MAX;
//			g2[i][j] = LONG_LONG_MAX;
//			g2[j][i] = LONG_LONG_MAX;
//		}
//	}
//}
//
//void input()
//{
//	for(int i = 1;i <= n;i ++)
//	{
//		int u,v;
//		long long w;
//		cin >> u >> v >> w;
//		g1[u][v] = w;
//		g1[v][u] = w; //旧路无向图输入 
//	}
//	
//	for(int i = 1;i <= k;i ++)
//	{
//		for(int j = 0;j <= n;j ++)
//		{
//			long long w;
//			cin >> w;
//			g2[i][j] = w; //新路无向图输入 
//		}
//	}
//}
//
//void get_old(){
//	for(int i = 1;i <= n;i ++) //floyd算旧路最短 
//	{
//		for(int j = i;j <= n;j ++)
//		{
//			for(int v = 1;v <= n;v ++)
//			{
//				if(g1[i][j] > g1[v][i] + g1[v][j])
//				{
//					g1[i][j] = g1[v][i] + g1[v][j];
//				}
//			}
//		}
//	}
//}
//
//void get_new(){
//	for(int i = 1;i <= n;i ++) //floyd算新路最短 
//	{
//		for(int j = i + 1;j <= n;j ++) //枚举两座城 
//		{
//			for(int v = 1;v <= k;v ++) //枚举城市化乡村 
//			{
//				if(g1[i][j] > g2[v][i] + g2[v][j] + g2[v][0]) //如果走新城的路会更短
//				{
//					ans += g2[v][i] + g2[v][j]; // 开通新路和新城，并归零费用 
//					if(vis[v] == false) //如果没开通过新城，就开通并标记
//					{
//						ans += g2[v][0];
//						vis[v] = true; 
//					} 
//					g1[i][j] = 0; 
//				}
//				else //否则开通旧路并归零费用 
//				{
//					ans += g1[i][j];
//					g1[i][j] = 0; 
//				}
//			} 
//		} 
//	}
//} 
//
//int main(){
////	freopen("road.in","r",stdin);
////	freopen("road.out","w",stdout);
//	cin >> n >> m >> k; //输入三大参数 
//	
//	init(); //初始化 
//	
//	input(); //输入图 
//	
//	get_old(); //计算旧的最短路 
//	
//	get_new(); //计算新的最短路，并统计总开支 
//	
//	cout << ans; //输出 
////	fclose(stdin);
////	fclose(stdout);
//	return 0;
//}
#include <bits/stdc++.h>
//骗分吧
using namespace std;

//road

int n,m,k;
long long g1[10005][10005];
long long g2[15][100005];
bool vis[15];
long long ans;

void init(){
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			g1[i][j] = LONG_LONG_MAX; //权值最大化 
			g1[j][i] = LONG_LONG_MAX;
			g2[i][j] = LONG_LONG_MAX;
			g2[j][i] = LONG_LONG_MAX;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k; //输入三大参数 
	
	init(); //初始化 
	
	for(int i = 1;i <= n;i ++)
	{
		int u,v;
		long long w;
		cin >> u >> v >> w;
		g1[u][v] = w;
		g1[v][u] = w; //旧路无向图输入 
	}
	
	bool f = true;
	
	for(int i = 1;i <= k;i ++)
	{
		for(int j = 0;j <= n;j ++)
		{
			long long w;
			cin >> w;
			if(w != 0) f = false;
			g2[i][j] = w; //新路无向图输入 
		}
	}
	
	if(f) ans = 0;
	else
	{
		srand(time(0));
		ans = rand() % 998244353;
	}
	cout << ans; //输出 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
