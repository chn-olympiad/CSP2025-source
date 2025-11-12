#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair < int, int > PII;
const int N = 1e5 + 5;
PII s[4][N];
int maxn[4][N];
int pos[4][N];
bool vis[N];
bool cmp(PII a, PII b)
{
	return a > b;
}
void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[1][i].fir >> s[2][i].fir >> s[3][i].fir;
		s[1][i].sec = s[2][i].sec = s[3][i].sec = i;
		PII maxf1 = {s[1][i].fir, 1}, maxs1 = {s[2][i].fir, 2}, maxt1 = {s[3][i].fir, 3};
		if(maxt1 > maxs1)swap(maxt1, maxs1);
		if(maxs1 > maxf1)swap(maxs1, maxf1);
		maxn[1][i] = maxf1.fir;
		maxn[2][i] = maxs1.fir;
		maxn[3][i] = maxt1.fir;
		pos[1][i] = maxf1.sec;
		pos[2][i] = maxs1.sec;
		pos[3][i] = maxt1.sec;
	}
	for(int i = 1; i <= 3; i++)sort(s[i] + 1, s[i] + n + 1, cmp);
	int num[4] = {0};
	int ans = 0;
	// cerr << ":";
	// for(int i = 1; i <= n; i++)
	// {
	// 	cerr << i << ":" << maxn[1][i] << " " << maxn[2][i] << " " << maxn[3][i] << "\n";
	// }
	for(int a = 1; a <= 3; a++)
	{
		for(int i = 1; i <= n && num[a] < n / 2; i++)
		{
			if(vis[s[a][i].sec])continue;
			// cerr << ">" << s[a][i].sec;
			if(maxn[1][s[a][i].sec] == s[a][i].fir)
			{
				// cerr << "!";
				ans += s[a][i].fir;
				vis[s[a][i].sec] = 1;
				num[a]++;
			}
			// cerr << "\n";
		}
		// cerr << "|";
		// for(int i = 1; i <= n; i++)cerr << vis[i] << " ";
		// cerr << "\n";
	}
	// for(int i = 1; i <= 3; i++)cerr << num[i] << " ";
	// cerr << "\n";
	cerr << ans << "\n";
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])continue;
		if(num[pos[1][i]] < n / 2)ans += maxn[1][i];
		else if(num[pos[2][i]] < n / 2)ans += maxn[2][i];
		else ans += maxn[3][i];
	}
	for(int i = 1; i <= n; i++)vis[i] = 0;
}
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("MyAnswer.out", "w", stdout);
	// freopen("Standard Error", "w", stderr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)solve();
	return 0;
}
