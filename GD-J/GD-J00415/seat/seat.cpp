#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node { int fenshu,id,c,r; }st[105];
bool cmp(Node a,Node b) { return a.fenshu > b.fenshu; }
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for (int i = 0;i < n * m;i++)
	{
		cin >> st[i].fenshu;
		st[i].id = i;
	}
	sort (st,st + n * m,cmp);
	st[0].c = 1;
	st[0].r = 1;
	if (st[0].id == 0)
	{
		cout << 1 << " " << 1;
		return 0;
	}
	for (int i = 1;i < n * m;i++)
	{
		int k = st[i - 1].c,p = st[i - 1].r;
		if (p % 2)
		{
			st[i].r = p;
			st[i].c = k + 1;
			if (st[i].c > n)
			{
				st[i].c = k;
				st[i].r = p + 1;
			}
		}
		else
		{
			st[i].r = p;
			st[i].c = k - 1;
			if (st[i].c < 1)
			{
				st[i].c = 1;
				st[i].r = p + 1;
			}
		}
		if (st[i].id == 0)
		{
			cout << st[i].r << " " << st[i].c;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
