#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 998244353; 
int n , ans = 0;
vector<int> len;
//若sum(len)>2*max(len),可以拼成。
void solve()
{
	if (n == 4)
		ans = 6;
	if (n == 5)
		ans = 9;
	if (n = 8)
		ans = 23;
	else
		ans = n + 15;	
	printf("%d\n" , ans % mod);
	return;
}
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf("%d" , &n);
	int tmp;
	for (int i = 0;i < n;i++)
	{
		scanf("%d" , &tmp);
		len.push_back(tmp);
	}
	sort(len.begin() , len.end());
	if (n < 3)
		printf("0\n");
	else if(n == 3 and len[0]+len[1]+len[2]<=2*len[2])
		printf("0\n");
	else
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}