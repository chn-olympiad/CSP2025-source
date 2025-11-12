#include <iostream>
#include <algorithm>
using namespace std;

const int M = 998244353;

int n, ans = 0;
int a[5010];

void dfs(int i, int sum, int maxn, int num)
{
	if (i > n)
	{
		if (sum > maxn * 2 && num >= 3)
		{
			ans++;
		}
		return;
	}
	
	dfs(i + 1, sum, maxn, num);
	dfs(i + 1, sum + a[i], max(maxn, a[i]), num + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);
	
	dfs(1, 0, 0, 0);
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//沟槽的美芬
//回家第一件事，打开kards竞技场。
//150金币一次，我非常癫狂。
//德国主国法国盟国，3张撤退坦克。
//还有俯冲懵逼哥，谁能如何我。
//正在寻找对手。
//卧槽完蛋，是沟槽的美芬。
//起手131伏击，这把也许有的办，希望对面手牌烂。
//什么T-26，466，还有蓝灰师。
//硬头皮交换撑后期，我还有俾斯麦兜底。
//什么惩戒逃离斩杀线。
//沟槽的激怒，沟槽的美芬，沟槽的冰岛入！
//1939工作室，快让美芬414。
//不然我就曼哈顿，你的工作室！ 
