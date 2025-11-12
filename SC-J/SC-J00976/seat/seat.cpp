#include <bits/stdc++.h>
using namespace std;
struct node
{
	int id,val;
};
bool cmp(node x,node y)
{
	return x.val > y.val;
}
node st[105];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int n_ = n;
	n = n * m;
	for(int i = 1;i <= n;i++)
	{
		cin >> st[i].val;
		st[i].id = i;
	}
	sort(st + 1,st + n + 1,cmp);
	for(int i = 1;i <= n;i++)
	{
		if(st[i].id == 1)
		{
			cout << ((i - 1) / n_) + 1 << " " << ((((i - 1) / n_) & 1)?(n_ - ((i - 1) % n_)):((i - 1) % n_ + 1));
			return 0;
		}
	}
	cout << n_ << " " << "1\n";
	return 0;
}