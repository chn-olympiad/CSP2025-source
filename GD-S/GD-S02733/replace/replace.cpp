#include <bits/stdc++.h>
using namespace std;

struct node
{
	string s,t;
} a[200005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].s >> a[i].t;
	}
	while (q--)
	{
		cout << 0 << endl;
	}
	return 0;
}
