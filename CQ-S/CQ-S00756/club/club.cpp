#include <bits/stdc++.h>
using namespace std;
long long n;
int mode = 1;
struct person
{
	int myd_to1;
	int myd_to2;
	int myd_to3;
	bool operator<(person b)
	{
		if (mode == 1)
		{
			return myd_to1 < b.myd_to1;
		}
		else if (mode == 2)
		{
			return myd_to2 < b.myd_to2;
		}
		else
		{
			return myd_to3 < b.myd_to3;
		}
	}
};
vector<person> people;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	for (int tx = 0; tx < t; tx++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			person pi;
			cin >> pi.myd_to1 >> pi.myd_to2 >> pi.myd_to3;
			people.push_back(pi);
		}
		//cout<<rand()<<'\n';
	}

	return 0;
}