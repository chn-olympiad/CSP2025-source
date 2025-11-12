#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005], s[5005];
bool vis[5005];

//窝要上迷惑行为大赏！！！ 
//好的还剩3分钟
//下午再唱吧。。。
//I LOVE CCF FOR EVER!!! 

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	if(n == 3)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(x + y > z && x + z > y && y + z > x)cout << 1;
		else cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a = n + 1);
	
	return 0;
} 
