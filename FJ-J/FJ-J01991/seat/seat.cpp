#include <bits/stdc++.h>
using namespace std;
int n,m,no,c,r;
struct Node{
	int num,id;
}a[10005];
bool cmp(Node x,Node y)
{
	return x.num > y.num;
}
void dfs(int x,int y,int yf,int step)
{
	if (step == no)
	{
		cout << x << " " << y << endl;
		return ;
	}
	if (y + yf > n || y + yf < 1)
		dfs(x + 1,y,-yf,step + 1);
	else
		dfs(x,y + yf,yf,step + 1);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
		cin >> a[i].num,a[i].id = i;
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
		if (a[i].id == 1)
		{
			no = i;
			break;
		}
	dfs(1,1,1,1);
	return 0;
}
