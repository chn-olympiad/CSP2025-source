#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int t, n, ans, sum;
int vis[N] = { 0 };
vector <int> sat[N];

void DFS(int depth = 1);

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while (t--)
    {
        sat[N].clear(); vis[0] = vis[1] = vis[2] = 0;
        ans = 0, sum = 0;
        cin >> n;
        for (int i = 1; i <= n;i++)
            for (int j = 0; j < 3; j++) cin >> sat[i][j];
       for (int i = 1; i <= n; i++)
       {
		   int val = 0, j = 0;
		   for(j = 0; j < 3; j++)
		   {
			   if (vis[j] > n / 2) continue;
				if (val < sat[i][j]) val = sat[i][j];
		   }
		   vis[j]++;
		   ans += val;
	   }
        cout << ans << '\n';
    }
    system("pause");
    return 0;
}

void DFS(int depth)
{
    if (depth == n + 1)
    {
        ans = max(ans,sum);
        return;
    }
    int val = 0, i = 0;
    while (val < sat[depth][i] && i < 3) 
    {
        if (vis[i] > n / 2) { i++; continue; }
        val = sat[depth][i];
        i++;
    }
    sum += val; vis[i]++;
    DFS(depth + 1);
}
