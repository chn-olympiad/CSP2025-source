#include <iostream>
#include <algorithm>
using namespace std;
int bm[4];
struct member
{
	int s[4],t[4],id[4] = {0,1,2,3};
}m[100005];
void _sort(member &a)
{
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 3-i; j++)
		{
			if (a.s[i] < a.s[i+1])
			{
				swap(a.s[j],a.s[j+1]);
				swap(a.id[j],a.id[j+1]);
			}
		}
	}
}
bool cmp(member a,member b)
{
	return a.s[a.id[1]] > b.s[b.id[1]];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,sumn=0;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> m[i].s[1] >> m[i].s[2] >> m[i].s[3];
			_sort(m[i]);
		}
		sort(m+1,m+n+1,cmp);
		for (int i = 1; i <= n; i++)
		{
			if (bm[m[i].id[1]] < n/2)
			{
				bm[m[i].id[1]]++;
				sumn += m[i].s[m[i].id[1]];
			}
			else if (bm[m[i].id[2]] < n/2)
			{
				bm[m[i].id[2]]++;
				sumn += m[i].s[m[i].id[2]];
			}
			else
			{
				bm[m[i].id[3]]++;
				sumn += m[i].s[m[i].id[3]];
			}
		}
		cout << sumn;
	}
	return 0;
} 
