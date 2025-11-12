#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;

int n, t, a[N][5];
int cnt1, cnt2, cnt3, cnt, ans;
typedef pair< pair<int, int> , pair<int, int> > PII;
priority_queue<PII, vector<PII>, greater<PII> > q1, q2, q3;

//窝要上迷惑行为大赏！！！
//可以的,经过窝不懈的努力
//也是成功过了大样例(夕夕
//好像燃尽了。。。
//窝开了三个优先队列
//每个放了四个值耶
//感觉T2是窝的克星。。。图论ToT
//窝没救惹ToT 
//(其实窝数学几何也不好ToT 
//I LOVE CCF FOR EVER!!! 

void tiao(int nw, int ch)
{
	int xx, yy;
	if(ch == 1)xx = 2, yy = 3;
	if(ch == 2)xx = 1, yy = 3;
	if(ch == 3)xx = 1, yy = 2;
	int l = a[nw][xx], r = a[nw][yy];
	if(l >= r)
	{
		if(xx == 1)q1.push({ {l - r, l}, {nw, xx} }), cnt1++;
		else if(xx == 2)q2.push({ {l - r, l}, {nw, xx} }), cnt2++;
		else if(xx == 3)q3.push({ {l - r, l}, {nw, xx} }), cnt3++;
		ans += l;
	}
	else
	{
		if(yy == 1)q1.push({ {l - r, r}, {nw, yy} }), cnt1++;
		else if(yy == 2)q2.push({ {l - r, r}, {nw, yy} }), cnt2++;
		else if(yy == 3)q3.push({ {l - r, r}, {nw, yy} }), cnt3++;
		ans += r;
	}
	return;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	for(int T = 1; T <= t; T++)
	{
		cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		
		cin >> n;
		
		cnt = n / 2;
		
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			
			int x = a[i][1], 
				y = a[i][2], 
				z = a[i][3];
				
			if(x == y && y == z)ans += x;
			
			if(x == y && y > z)ans += x;
			if(x == z && x > y)ans += x;
			if(z == y && y > x)ans += y;
			
			if(x > y && x > z)
			{
				cnt1++;
				if(y > z)q1.push({ {x - y, x}, {i, 1} });
				else q1.push({ {x - z, x}, {i, 1} });
				ans += x;
				
				if(cnt1 > cnt)
				{
					cnt1--;
					int h = q1.top().second.first;
					int g = q1.top().second.second;
					tiao(h, g);
					ans -= q1.top().first.second;
					q1.pop();
				}
			}
			if(y > x && y > z)
			{
				cnt2++;
				if(x > z)q2.push({ {y - x, y}, {i, 2} });
				else q2.push({ {y - z, y}, {i, 2} });
				ans += y;
				
				if(cnt2 > cnt)
				{
					cnt2--;
					int h = q2.top().second.first;
					int g = q2.top().second.second;
					tiao(h, g);
					ans -= q2.top().first.second;
					q2.pop();
				}
			}
			if(z > y && z > x)
			{
				cnt3++;
				if(x > y)q3.push({ {z - x, z}, {i, 3} });
				else q3.push({ {z - y, z}, {i, 3} });
				ans += z;
				
				if(cnt3 > cnt)
				{
					cnt3--;
					int h = q3.top().second.first;
					int g = q3.top().second.second;
					tiao(h, g);
					ans -= q3.top().first.second;
					q3.pop();
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
