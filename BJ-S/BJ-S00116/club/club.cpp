#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id, bes, bet;
};
vector<node> G1, G2, G3;
int a[100005][5];
bool cmp(node x, node y)
{
	return a[x.id][x.bes] - a[x.id][x.bet] > a[y.id][y.bes] - a[y.id][y.bet];
}
void calc()
{
	int ans = 0;
	for(int i = 0; i < G1.size(); i ++) ans += a[G1[i].id][1];
	//cout <<endl;
	for(int i = 0; i < G2.size(); i ++) ans += a[G2[i].id][2];
	//cout << endl;
	for(int i = 0; i < G3.size(); i ++) ans += a[G3[i].id][3];
	//cout <<endl;
	cout << ans << endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	cin >> _;
	while(_ --)
	{
		G1.clear(), G2.clear(), G3.clear();
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			{
				G1.push_back(node{i, 1, (a[i][2] >= a[i][3] ? 2 : 3)});
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
			{
				G2.push_back(node{i, 2, (a[i][1] >= a[i][3] ? 1 : 3)});
			}
			else
			{
				G3.push_back(node{i, 3, (a[i][1] >= a[i][2] ? 1 : 2)});
			}
		}
		if(G1.size() <= n / 2 && G2.size() <= n / 2 && G3.size() <= n / 2)
		{
			calc();
		}
		else
		{
			if(G1.size() > n / 2)
			{
				sort(G1.begin(), G1.end(), cmp);
				while(G1.size() > n / 2)
				{
					node x = G1[G1.size() - 1];
					G1.pop_back();
					if(x.bet == 2) G2.push_back(x);
					else G3.push_back(x);
				}
				calc();
			}
			else if(G2.size() > n / 2)
			{
				sort(G2.begin(), G2.end(), cmp);
				while(G2.size() > n / 2)
				{
					node x = G2[G2.size() - 1];
					G2.pop_back();
					if(x.bet == 1) G1.push_back(x);
					else G3.push_back(x);
				}
				calc();
			}
			else
			{
				sort(G3.begin(), G3.end(), cmp);
				while(G3.size() > n / 2)
				{
					node x = G3[G3.size() - 1];
					G3.pop_back();
					if(x.bet == 1) G1.push_back(x);
					else G2.push_back(x);
				}
				calc();
			}
		}
	}
	return 0;
}
