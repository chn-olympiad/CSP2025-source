#include <iostream>
using namespace std;

int ltt[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ltt[i];
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum ^ ltt[j];
			if (sum == k)
			{
//				cout << i << " " << j << endl;
//				cout << sum << endl;
				cnt++;
				i = j;
//				cout << "now i am " << i << endl;
				break;
			}
//			cout << "failed:" << sum << " " << i << " " << j << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}
