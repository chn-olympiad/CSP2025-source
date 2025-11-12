//it's luogu user 1383883
/*
《别了，OI》 
这一切都在我的指尖逝去了。
100+0+25+10
记得自己第一次学习OI是小六早培的时候。
当时正在半期考试，由于我之前的课都没有听，为了不垫底，我在考试的时候边翻书边写，结果最后我考了第7名。当时我觉得自己一定有天赋在这里，于是这一切就都在此开始了。
后面正式入学的时候我没有报编程社，也许我就此与OI毫无瓜葛了。
可是老天开了个玩笑，寒假上竞赛课的时候，又有信竞课。我又重新燃起了对OI的热情。
我永远不会忘记那个夜晚，那个听教练一对一讲错排问题，最后留到十一点的夜晚。
风依旧摇曳。 
一切都那么美好。
后来我就复入信竞队了。
匆匆归来，又匆匆离去。
我似乎是有些得意了，deepseek的出现更是暴露了我自制力不足的本质，即使在最后意识到了这一切，但也为时已晚
暑假前我遇到了一件对我打击巨大的事，表白失败。我不明白自己追求的是什么，但这已经发生。
集训的时候我就在颓废。 
然后开学的时候我因为文化课被刷了，幸好有CSP，让我可以继续留下来。我意识到自己需要改变 

*/
//No one cares you else yourself.
#include<bits/stdc++.h>
using namespace std;
int T;	
struct node
{
	int s1;
	int s2;
	int s3;
	int max1, id1;
	int max2, id2;
	int max3, id3;
	int diff12;
	int diff23;
	int vis = 0;//0:1->2,1:2->3,-1:can't do it
	int id;
};
bool cmp(node &a, node &b)
{
	if (a.id2 == 0)
	{
		map<int, int> mp;
		int as[4];
		mp[a.s1] = 1, mp[a.s2] = 2, mp[a.s3] = 3; 
		as[1] = a.s1, as[2] = a.s2, as[3] = a.s3;
		sort(as + 1, as + 4);
		a.max1 = as[3], a.max2 = as[2], a.max3 = as[1];
		a.id1 = mp[as[3]], a.id2 = mp[as[2]], a.id3 = mp[as[1]];
		a.diff12 = a.max1 - a.max2;
		a.diff23 = a.max2 - a.max3;
	} 
	if (b.id2 == 0)
	{
		map<int, int> mp2;
		int bs[4];
		mp2[b.s1] = 1, mp2[b.s2] = 2, mp2[b.s3] = 3;
		bs[1] = b.s1, bs[2] = b.s2, bs[3] = b.s3;
		sort(bs + 1, bs + 4);
		b.max1 = bs[3], b.max2 = bs[2], b.max3 = bs[1];
		b.id1 = mp2[bs[3]], b.id2 = mp2[bs[2]], b.id3 = mp2[bs[1]];
		b.diff12 = b.max1 - b.max2;
		b.diff23 = b.max2 - b.max3;
	}
	if (a.max1 != b.max1)
	{
		return a.max1 > b.max1;
	}
	if (a.max2 != b.max2)
	{
		return a.max2 > b.max2;
	}
	if (a.max3 != b.max3)
	{
		return a.max3 > b.max3;
	}
	return true;
}
bool cmp1(node a, node b)
{
	int cmpa = (a.vis) ? a.diff23 : a.diff12;
	int cmpb = (b.vis) ? b.diff23 : b.diff12;
	return cmpa < cmpb;
}
void solve()
{
	int n;
	cin >> n;
	vector<node> a(n + 5);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
		a[i].vis = 0;
	}
	sort(a.begin() + 1, a.begin() + n + 1, cmp);
	int tot[4] = {0};
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += a[i].max1;
		tot[a[i].id1]++;
	}
	while (tot[1] > n / 2 || tot[2] > n / 2 || tot[3] > n / 2)
	{
		if (tot[1] > n / 2)
		{
			vector<node> newa;
			for (int i = 1; i <= n; i++)
			{
				if ((a[i].id1 == 1 && !a[i].vis) || (a[i].id2 == 1 && a[i].vis == 1))
				{
					newa.push_back(a[i]);
				}
				a[i].id = i;
			}
			sort(newa.begin(), newa.end(), cmp1);
			int i = 0;
			while (tot[1] > n / 2)
			{
				if (!newa[i].vis)
				{
					ans -= newa[i].max1;
					tot[1]--;
					a[newa[i].id].vis = 1;
					ans += newa[i].max2;
					tot[newa[i].id2]++;
					i++;
				}
				else
				{
					ans -= newa[i].max2;
					tot[1]--;
					a[newa[i].id2].vis = -1;
					ans += newa[i].max3;
					tot[newa[i].id3]++;
					i++;
				}
			}
		}
		if (tot[2] > n / 2)
		{
			vector<node> newa;
			for (int i = 1; i <= n; i++)
			{
				if ((a[i].id1 == 2 && !a[i].vis) || (a[i].id2 == 2 && a[i].vis == 1))
				{
					newa.push_back(a[i]);
				}
				a[i].id = i;
			}
			sort(newa.begin(), newa.end(), cmp1);
			int i = 0;
			while (tot[2] > n / 2)
			{
				if (!newa[i].vis)
				{
					ans -= newa[i].max1;
					tot[2]--;
					a[newa[i].id].vis = 1;
					ans += newa[i].max2;
					tot[newa[i].id2]++;
					i++;
				}
				else
				{
					ans -= newa[i].max2;
					tot[2]--;
					a[newa[i].id2].vis = -1;
					ans += newa[i].max3;
					tot[newa[i].id3]++;
					i++;
				}
			}
		}
		if (tot[3] > n / 2)
		{
			vector<node> newa;
			for (int i = 1; i <= n; i++)
			{
				if ((a[i].id1 == 3 && !a[i].vis) || (a[i].id2 == 3 && a[i].vis == 1))
				{
					newa.push_back(a[i]);
				}
				a[i].id = i;
			}
			sort(newa.begin(), newa.end(), cmp1);
			int i = 0;
			while (tot[3] > n / 2)
			{
				if (!newa[i].vis)
				{
					ans -= newa[i].max1;
					tot[3]--;
					a[newa[i].id].vis = 1;
					ans += newa[i].max2;
					tot[newa[i].id2]++;
					i++;
				}
				else
				{
					ans -= newa[i].max2;
					tot[3]--;
					a[newa[i].id2].vis = -1;
					ans += newa[i].max3;
					tot[newa[i].id3]++;
					i++;
				}
			}
		}
	}
	cout << ans << "\n";
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
