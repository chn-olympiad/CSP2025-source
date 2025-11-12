#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

struct satisfaction
{
	int a1, a2, a3;
}student[MAXN];

bool cmp(satisfaction a, satisfaction b)
{
	return a.a1 > b.a1;
}

int main()
{
 	freopen("club.in", "r", stdin);
 	freopen("club.out", "w", stdout);
 	int t;
 	
 	cin >> t;
 	
 	for(int i = 1; i <= t; i++)
 	{
 		int n;
 		int maxn = 0;
 		
 		cin >> n;
 		for(int j = 1; j <= n; j++)
 		{
 			cin >> student[j].a1 >> student[j].a2 >> student[j].a3;
		}
		sort(student + 1, student + n + 1, cmp);
		for(int j = 1; j <= n / 2; j++)
		{
			maxn += student[j].a1;
		}
		cout << maxn << endl;
	}
	return 0;
}


