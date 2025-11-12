#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	int z;
}a[100005];

int finded(vector <int> o,int j)
{
	for (int i = 0; i < o.size(); i++)
	{
		if(o[i] == j)
		{
			return i;
		}
	}
}

bool cmp1(int l,int b)
{
	return a[l].x >= a[b].x;
}

bool cmp2(int l,int b)
{
	return a[l].y >= a[b].y;
}

bool cmp3(int l,int b)
{
	return a[l].z >= a[b].z;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;
		
		vector <int> a1;
		vector <int> a2;
		vector <int> a3;
		
		a1.push_back(0);
		a2.push_back(0);
		a3.push_back(0);
		
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x;
			cin >> a[i].y;
			cin >> a[i].z;

			a1.push_back(i);
			a2.push_back(i);
			a3.push_back(i);
		}
		
		sort (a1.begin(), a1.end(),cmp1);	
		sort (a2.begin(), a2.end(),cmp2);	
		sort (a3.begin(), a3.end(),cmp3);
		
		for (int i = 1; i <= n; i++)
		{
			int f1 = finded(a1,i);
			int f2 = finded(a2,i);
			int f3 = finded(a3,i);
			
			if (a1.size() <= n/2 && a2.size() <= n/2 && a3.size() <= n/2)
			{
				int ans = 0;
			for (int i = 0; i < a1.size(); i++)
			{
				ans += a[a1[i]].x;
			}
			for (int i = 0; i < a3.size(); i++)
			{
				ans += a[a2[i]].y;
			}
			for (int i = 0; i < a3.size(); i++)
			{
				ans += a[a3[i]].z;
			}
			cout << ans <<endl;
			}
			else if (f1 <= n/2 && f2 <= n/2 && f3 <= n/2)
			{
				if (a[f1].x - a[a1[f1+1]].x >= a[f2].y - a[a2[f2+1]].y && a[f1].x - a[a1[f1+1]].x >= a[f3].z - a[a3[f3+1]].z)
				{
					
				}
				else
				{
					a1.erase(a1.begin() + f1 +1);
					if (a[f2].y - a[a2[f2+1]].y >= a[f3].z - a[a3[f3+1]].z)
					{
						a3.erase(a3.begin() + 1 + f3);
					}
					else
					{
						a2.erase(a2.begin() + f2 +1);
					}
				}
			}
			else if (f1 <= n/2 && f2 <= n/2)
			{
				if (a[f1].x - a[a1[f1+1]].x >= a[f2].y - a[a2[f2+1]].y)
				{
					a2.erase(a2.begin() + f2 +1);
				}
				else
				{
					a1.erase(a1.begin() + f1 +1);
				}
			}
			else if (f1 <= n/2 && f3 <= n/2)
			{
				if (a[f1].x - a[a1[f1+1]].x >= a[f3].z - a[a3[f3+1]].z)
				{
					a3.erase(a3.begin() + 1 + f3);
				}
				else
				{
					a1.erase(a1.begin() + f1 +1);
				}
			}
			else if (f2 <= n/2 && f3 <= n/2)
			{
				if (a[f2].y - a[a2[f2+1]].y >= a[f3].z - a[a3[f3+1]].z)
				{
					a3.erase(a3.begin() + 1 + f3);
				}
				else
				{
					a2.erase(a2.begin() + f2 +1);
				}
			}
		}
		int ans = 0;
		
		for (int i = 1; i <= a1.size(); i++) ans+= a[a1[i]].x;
		for (int i = 1; i <= a2.size(); i++) ans+= a[a2[i]].y;
		for (int i = 1; i <= a3.size(); i++) ans+= a[a3[i]].z;
		
		cout << ans <<endl;	
	}
	
	return 0;
}
