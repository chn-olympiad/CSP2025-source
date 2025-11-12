#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

struct point
{
	int x, y;
};

int n, m;
int score[N * N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++ i )
		scanf("%d", &score[i]);
	
	int first = score[1];
	sort(score + 1, score + 1 + n * m, greater <int>());
	
	int idx = 0;
	for (int i = 1; i <= n * m; ++ i )
		if (score[i] == first)
		{
			idx = i;
			break;
		}
	
	int cnt1 = (idx - 1) / (2 * n);
	int cnt2 = idx % (2 * n);
	if (!cnt2) cnt2 = n;
	
	if (cnt2 <= n) printf("%d %d\n", cnt1 * 2 + 1, cnt2);
	else printf("%d %d\n", cnt1 * 2 + 2, n - cnt2 + n + 1);
	
//	printf("\n\n%d\n\n", idx);
	return 0;
}
