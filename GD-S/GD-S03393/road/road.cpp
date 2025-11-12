/*
	感觉是FLoyd,先做特殊性质
*/
#include <iostream>
#include <ctime>
#include <vector>

#ifdef _WIN32
double __begin_clock = clock();
#endif

#define FILE_IO_NAME "road"

constexpr int MAXN = static_cast<int>(1e4 + 20);
constexpr int MAXM = static_cast<int>(1e6 + 20);
constexpr int MAXK = static_cast<int>(15);

int n, m, k;

int adj_matrix[MAXN][MAXN];
int fix_fee[MAXK][MAXN];

inline void initialize()
{
//	for(int i = 0; i < MAXN; i++)
//	{
//		for(int j = 0; j < MAXN; j++)
//		{
//			adj_matrix[i][j] = 0;
//		}
//	}
}

bool is_special_case = true;

inline void process_input()
{
	std::cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		static int u, v, w;
		std::cin >> u >> v >> w;
		adj_matrix[u][v] = w;
		adj_matrix[v][u] = w;
	}

	for(int j = 1; j <= k; j++)
	{
		std::cin>>fix_fee[j][0];
		for(int i = 1; i <= n; i++)
		{
			std::cin>>fix_fee[j][i];
			adj_matrix[n+j][i] = fix_fee[j][i];
		}
		if(fix_fee[j][0] != 0)
		{
			is_special_case = false;
		}
	}
}

inline void floyd()
{
	for(int l = 1; l <= n; l++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				{
					adj_matrix[i][j] = std::min(adj_matrix[i][j],adj_matrix[i][l] + adj_matrix[l][j]);
				}
			}
		}
	}

}

int answer = -114514;

inline void solve()
{
	process_input();
	floyd();
	for(int i = 1; i <= n + k; i++)
	{
		for(int j = 1; j <= n + k; j++)
		{
			answer = std::max(answer,adj_matrix[i][j]);
		}
	}
	std::cout<<answer<<"\n";
}

int main()
{
	freopen(FILE_IO_NAME".in","r",stdin);
	freopen(FILE_IO_NAME".out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

#ifdef _WIN32
	std::cerr << "Time Cost:" << (clock() - __begin_clock)/1000 << "s\n";
#endif
	return 0;
}
