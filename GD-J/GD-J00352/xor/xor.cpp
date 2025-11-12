#include <iostream>
#include <algorithm>
using namespace std;


int n, k, arr[500001], p[500001];
struct Node
{
	int ll, rr;
} q[500001];
int top, cnt = 0;

bool cmp(Node x, Node y)
{
	return x.rr > y.rr;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		p[i] = arr[i] ^ p[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if ((p[j] ^ p[i - 1]) == k)
				q[++top] = {i, j};
	q[0] = {0x3f3f3f3f, 0x3f3f3f3f};
	
	
	sort(q + 1, q + top + 1, cmp);
	for (int i = 1; i <= top; i++)
		cout << q[i].ll << ' ' << q[i].rr << endl;
	for (int l = 0, i = 1; i <= top; i++)
	{
		if (q[i].rr >= q[l].ll)
		{
			if (q[i].ll >= q[l].ll)
				l = i;
		}
		else
		{
			cnt++;
			l = i;
		}
	}
	
	cout << cnt;
	
	return 0;
} 
