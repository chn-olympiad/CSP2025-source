#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
struct Scorex
{
	int a,id;
}sc[N];
bool cmp(Scorex x, Scorex y)
{
	return x.a > y.a; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> sc[i].a;
		sc[i].id = i;
	}
	sort(sc+1,sc+n*m+1,cmp);
	int pos = 0;
	for (int i = 1; i <= n*m; i++) if (sc[i].id == 1)
	{
		pos = i;
		break;
	}
	int cur = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++) if (++cur == pos)
			{
				cout << i << " " << j;
				break;
			}
		}
		else
		{
			for (int j = n; j >= 1; j--) if (++cur == pos)
			{
				cout << i << " " << j;
				break;
			}
		}
	}
	return 0;
}
