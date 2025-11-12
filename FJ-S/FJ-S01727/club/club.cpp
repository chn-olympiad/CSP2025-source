#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
//f:sum s:id
struct Node{
	pair<long long,long long> b[4];
	long long c[4];
}a[100005];
bool cmpa(pair<long long,long long> x,pair<long long,long long> y)
{
	return x.first < y.first;
}
bool cmpc(pair<long long,long long> x,pair<long long,long long> y)
{
	return a[x.second].b[a[x.second].c[2]].first - x.first < a[y.second].b[a[y.second].c[2]].first - y.first;
}
bool cmpd(pair<long long,long long> x,pair<long long,long long> y)
{
	return a[x.second].b[a[x.second].c[3]].first - x.first < a[y.second].b[a[y.second].c[3]].first - y.first;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		ans = 0;
		vector<pair<long long,long long> > v[4];
		cin >> n;
		for (long long i = 1;i <= n;i++)
		{
			a[i].b[1].second = 1,a[i].b[2].second = 2,a[i].b[3].second = 3;
			cin >> a[i].b[1].first >> a[i].b[2].first >> a[i].b[3].first;
			sort(a[i].b + 1,a[i].b + 4,cmpa);
			a[i].c[a[i].b[1].second] = 1,a[i].c[a[i].b[2].second] = 2,a[i].c[a[i].b[3].second] = 3;
		}
		for (long long i = 1;i <= n;i++)
			v[1].push_back({a[i].b[a[i].c[1]].first,i});
		if (v[1].size() > n / 2)
		{
			vector<pair<long long,long long> > vec;
			sort(v[1].begin(),v[1].end(),cmpc);
//			for (long long i = 0;i < v[1].size();i++)
//				cout << v[1][i].first << " ";
//			cout << endl;
			for (long long i = 0;i < n / 2;i++)
				vec.push_back(v[1][i]);
			for (long long i = n / 2;i < v[1].size();i++)
			{
				if (a[v[1][i].second].b[a[v[1][i].second].c[2]].first > a[v[1][i].second].b[a[v[1][i].second].c[3]].first)
					v[2].push_back({a[v[1][i].second].b[a[v[1][i].second].c[2]].first,v[1][i].second});
				else
					v[3].push_back({a[v[1][i].second].b[a[v[1][i].second].c[3]].first,v[1][i].second});
			}
			swap(v[1],vec);
		}
//		if (v[1].size() < n / 2)
//		{
//			int k = 0;
//			vector<pair<int,int> > vec;
//			sort(v[1].begin(),v[1].end(),cmpc);
//			for (k = v[1].size() - 1;k >= 0;k--)
//				if (a[v[1][k].second].b[a[v[1][k].second].c[2]].first - v[1][k].first <= 0)
//					break;
//			if (k < n / 2)
//			{
//				for (int i = 0;i < k;i++)
//					vec.push_back(v[1][i]);
//				for (int i = k;i < v[1].size();i++)
//					v[2].push_back({a[v[1][i].second].b[a[v[1][i].second].c[2]].first,v[1][i].second});
//				swap(v[1],vec);
//			}
//		}
		if (v[2].size() > n / 2)
		{
			vector<pair<long long,long long> > vec;
			sort(v[2].begin(),v[2].end(),cmpd);
//			for (long long i = 0;i < v[2].size();i++)
//				cout << v[2][i].first << " ";
//			cout << endl;
			for (long long i = 0;i < n / 2;i++)
				vec.push_back(v[2][i]);
			for (long long i = n / 2;i < v[2].size();i++)
				v[3].push_back({a[v[2][i].second].b[a[v[2][i].second].c[3]].first,v[2][i].second});
			swap(v[2],vec);
		}
//		if (v[2].size() < n / 2)
//		{
//			int k = 0;
//			vector<pair<int,int> > vec;
//			sort(v[2].begin(),v[2].end(),cmpd);
//			for (k = v[2].size() - 1;k >= 0;k--)
//				if (a[v[2][k].second].b[a[v[2][k].second].c[3]].first - v[2][k].first <= 0)
//					break;
//			if (k < n / 2)
//			{
//				for (int i = 0;i < k;i++)
//					vec.push_back(v[2][i]);
//				for (int i = k;i < v[2].size();i++)
//					v[3].push_back({a[v[2][i].second].b[a[v[2][i].second].c[3]].first,v[2][i].second});
//				swap(v[2],vec);
//			}
//		}
		for (long long i = 1;i <= 3;i++)
			for (long long j = 0;j < min(n / 2,(long long)v[i].size());j++)
				ans += v[i][j].first;
//		for (int i = 1;i <= 3;i++)
//			for (int j = 0;j < min(n / 2,(int)v[i].size());j++)
//				cout << i << " " << j << ":" << v[i][j].first << endl;
		cout << ans << endl;
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
