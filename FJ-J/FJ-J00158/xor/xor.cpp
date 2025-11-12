#include <vector>
#include <iostream>

using namespace std;

const int N = 500010;

int n, m;
int Xor[N];
vector <int> idx[1050000];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i )
		scanf("%d", &Xor[i]), Xor[i] ^= Xor[i - 1];
	
	for (int i = n; i >= 1; -- i )
		idx[Xor[i]].push_back(i);
	idx[0].push_back(0);
	
//	for (int i = 0; i <= 10; ++ i )
//	{
//		printf("%d: ", i);
//		for (auto j : idx[i]) printf("%d ", j);
//		putchar('\n');
//	}
//	putchar('\n');

	if (!m)
	{
		int res = 0;
		for (int i = 0; i < 1050000; ++ i )
			res = max(res, (int)idx[i].size() - 1);
		return printf("%d\n", res), 0;
	}
	
	int res = 0;
	int last = 0;
	while (last <= n && last >= 0)
	{
//		if (last) return 0;
		int cur_mi = n + 1;
		
//		printf("%d:  ", last);
		for (int i = last; i <= n; ++ i )
		{
			if (!idx[m ^ Xor[i]].size() || idx[m ^ Xor[i]].back() == last) continue;
			cur_mi = min(cur_mi, idx[m ^ Xor[i]].back());
//			if (cur_mi < last) return last;S
//			printf("[%d, %d] ", m ^ Xor[i], idx[m ^ Xor[i]].back());
		}
//		putchar('\n');
		
		if (cur_mi == n + 1 || cur_mi < last) break;
		for (int i = last; i < cur_mi; ++ i )
			idx[Xor[i]].pop_back();
		res ++ ;
//		printf("%d %d\n", last, cur_mi);
//		if (!last) return printf("%d %d\n", last, cur_mi), cur_mi;
		
		last = cur_mi;
	}
//	return 0;
	printf("%d\n", res);
	return 0;
}
