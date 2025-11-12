#include <iostream>
#include <algorithm>
using namespace std;
int yihuo[500005];
struct Node {int pzuo,pyou; }zu[500005];
bool cmp(Node a,Node b)
{
	if (a.pyou != b.pyou) return a.pyou < b.pyou;
	return a.pzuo > b.pyou;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		int shu;
		cin >> shu;
		yihuo[i] = yihuo[i - 1] ^ shu;
	}
	int biao = 0;
	for (int zuo = 1;zuo <= n;zuo++)
	{
		for (int you = zuo;you <= n;you++)
		{
			int m = yihuo[you] ^ yihuo[zuo - 1];
			if (m == k)
			{
				zu[biao] = {zuo,you};
				biao++;
			}
		}
	}
	sort(zu,zu + biao,cmp);
	int ans = 1;
	int kyou = zu[0].pyou;
	for (int i = 1;i < biao;i++)
	{
		if (zu[i].pzuo > kyou)
		{
			kyou = zu[i].pyou;
			ans++;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
