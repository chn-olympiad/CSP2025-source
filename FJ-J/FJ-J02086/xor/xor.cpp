#include <iostream>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[500005];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	int cnt = 0;
	int i = 1;
	for (int j = 1; j <= n; j++){
		sum = sum ^ a[j];
		while (sum >= k){
			if (sum == k){
				cnt++;
				i++;
				break;
			}
			int now = 0;
			for (int r = i + 1; r <= j; r++)
				now = now ^ a[r];
			sum = now;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
