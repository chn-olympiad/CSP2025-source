#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n;
ll sum;
struct peo
{
	pair <ll,int> ap[4];
	pair <ll,int>& operator [] (int pos)
	{
		return ap[pos];
	}
	void GetInp()
	{
		for(int i = 1;i <= 3;i++)
		{
			cin >> ap[i].first;
			ap[i].second = i;
		}
		sort(ap + 1,ap + 4);
	}
	int Getc(int pos)
	{
		return pos == 1 ? -1 : ap[pos].first - ap[pos - 1].first;
	}
}a[N];
bool cmp(peo A,peo B)
{
	for(int i = 3;i > 1;i--)
	{
		int c1 = A.Getc(i),c2 = B.Getc(i);
		if(c1 != c2)
			return c1 > c2;
	}
	return false;
}
priority_queue <int,vector <int>,greater <int>> pq[4];
bool Change(int p,int t)
{
	int apar = a[p][t].second; 
	if(pq[apar].size() < n / 2)
	{
		pq[apar].push(p);
		return true;
	}
	return false;
}
void Solve()
{
	sum = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= 3;j++)
			a[i][j] = make_pair(0,0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		a[i].GetInp();
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
		for(int j = 3;j > 0;j--)
			if(Change(i,j))
				break;
	for(int i = 1;i <= 3;i++)
	{
		while(!pq[i].empty())
		{
			int tmp = pq[i].top();
			for(int j = 1;j <= 3;j++)
			{
				if(a[tmp][j].second == i)
				{
					sum += a[tmp][j].first;
					break;
				}
			}
			pq[i].pop();
		}
	}
	cout << sum << '\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		Solve();
	return 0;
}
