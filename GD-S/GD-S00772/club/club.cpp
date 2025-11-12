#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
template<class T>void Max(T &x,T y){if (y>x) x=y;}
const int N=100010;
int n;
struct stu { int w[3]; } club[N];

namespace Subtask
{
	int id[N];
	void work()
	{
		for (int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,[&](int x,int y)
		{
			return club[x].w[0]-club[x].w[1]>club[y].w[0]-club[y].w[1];
		});
		ll ans=0;
		for (int i=1;i<=n/2;i++) ans+=club[id[i]].w[0];
		for (int i=n/2+1;i<=n;i++) ans+=club[id[i]].w[1];
		cout << ans << "\n";
	}
}
namespace Brute
{
	const int N=210;
	ll f[N][N][N];
	void work()
	{
		for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) for (int k=0;k<=n;k++) f[i][j][k]=-1e18;
		f[0][0][0]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=i;j++)
			{
				for (int k=0;j+k<=i;k++)
				{
					if (j) Max(f[i][j][k],f[i-1][j-1][k]+club[i].w[0]);
					if (k) Max(f[i][j][k],f[i-1][j][k-1]+club[i].w[1]);
					Max(f[i][j][k],f[i-1][j][k]+club[i].w[2]);
				}
			}
		}
		ll ans=0;
		for (int j=0;j<=n/2;j++) 
		{
			for (int k=0;k<=n/2;k++)
			{
				int c=n-j-k;
				if (c<=n/2) Max(ans,f[n][j][k]);
			}
		}
		cout << ans << "\n";
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	int T; cin >> T;
	while (T--)
	{
		cin >> n; bool flag=true;
		for (int i=1;i<=n;i++) 
		{
			int a,b,c; cin >> a >> b >> c;
			club[i].w[0]=a; club[i].w[1]=b; club[i].w[2]=c; 
			if (c>0) flag=false;
		}
		if (flag) Subtask::work();
		else Brute::work();
	}
	return 0;
} 

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
