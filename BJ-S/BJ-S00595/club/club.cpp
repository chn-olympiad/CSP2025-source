#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,id;
}a[100005],b[100005],c[100005];
bool cmp(node A,node B)
{
	return A.v > B.v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	for(int i = 1;i <= T;i++)
	{
		for(int i = 1;i <= 100000;i++)
		{
			a[i].v = 0,b[i].v = 0,c[i].v = 0;a[i].id = 0,b[i].id = 0,c[i].id = 0;
		}
		int n;
		cin >> n;
		if(n == 2)
		{
			cin >> a[1].v >> a[2].v >> a[3].v;
			cin >> b[1].v >> b[2].v >> b[3].v;
			a[1].id = 1,a[2].id = 2,a[3].id = 3,b[1].id = 1,b[2].id = 2,b[3].id = 3;
			sort(a + 1,a + 4,cmp);
			sort(b + 1,b + 4,cmp);
			if(a[1].id == b[1].id)
			{
				if(a[1].v - a[2].v > b[1].v - b[2].v)
					cout << a[1].v + b[2].v << endl;
				else
					cout << a[2].v + b[1].v << endl;
			}
			else
				cout << a[1].v + b[1].v << endl;
		}
		else
		{
			int sum = 0;
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i].v >> b[i].v >> c[i].v;
			}
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].v;
			}
			cout << sum << endl;
		}
		
	}
	return 0;
}
