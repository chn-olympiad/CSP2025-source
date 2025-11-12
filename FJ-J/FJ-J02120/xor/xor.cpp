#include <iostream>
#include <algorithm>
using namespace std;

int a[500010];

struct node
{
	int l, r;
} x[1000010];

bool cmp(node xx, node yy)
{
	if (xx.r != yy.r) return xx.r < yy.r;
	return xx.l > yy.l;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0, cur = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = a[i];
		if (a[i] == k)
		{
			cur++;
			x[cur].l = x[cur].r = i;
		}
		for (int j = i + 1; j <= n; j++)
		{
			sum ^= a[j];
			if (sum == k)
			{
				cur++;
				x[cur].l = i;
				x[cur].r = j;
			}
		}
	}
	sort(x + 1, x + cur + 1, cmp);
	int last = 0;
	for (int i = 1; i <= cur; i++)
	{
		if (last < x[i].l)
		{
			ans++;
			last = x[i].r;
		}
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//必养的自残苏
//新的赛季，能人辈出，上赛季的奖励我领地舒服。
//我想打开天梯，把对面全打服。
//哪怕遇到日快，也绝不认输。
//开始第一局，对面主国苏，一无所知的我开始欢呼。
//敌方先手，112打出。
//一张拉伸那是十分威武。
//213的守护兵，2费自残T-35。
//3费准时354，守护兵身材赛老鼠。
//镰刀，还有自残弹，手撕大件如杀猪。
//最可恨的766，3费就直接拍出。
//最快只有5回合，KV-2就在那一杵。
//必养的自残苏，谁遇到谁就输。
//馒头海根本不敢看，日快直接吓哭。
//天梯的新爹全由铜铁浇筑，拉伸之主。
//必养的自残苏！ 
