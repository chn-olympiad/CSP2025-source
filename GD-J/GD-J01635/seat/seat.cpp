#include <bits/stdc++.h>
using namespace std;

struct node
{
	int num, id;	
};
node a[105];
bool cmp(node x, node y)
{
	return x.num > y.num;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i].num;
	for(int i = 1; i <= n * m; i++) a[i].id = i;
	sort(a + 1, a + n * m + 1, cmp);
	bool down = 1;
	int nowx = 1, nowy = 1;
	int cnt = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i].id == 1)	
		{
			cout << nowx << " " << nowy << endl;
			break;
		}
		if(nowy == m && down)	
		{
			down = 0;
			nowx++;
		}
		else if(nowy == 1 && !down)
		{
			down = 1;
			nowx++;
		}
		else if(down)
		{
			nowy++;
		}
		else
		{
			nowy--;
		}
	}
	return 0;
}
