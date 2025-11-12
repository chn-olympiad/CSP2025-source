#include<iostream>
using namespace std;
int a[100005][5];
int hope[5];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t, n;
	cin >> t;
	
	while (t--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin >> a[i][j];
		
		for(int i=1;i<=3;i++)
			hope[i] = 0;
		int ag = 0;
		
		for(int i=1;i<=n;i++){
			ag += max(max(a[i][1], a[i][2]), a[i][3]);
			if (max(max(a[i][1], a[i][2]), a[i][3]) == a[i][1])
				hope[1]++;
			else if (max(max(a[i][1], a[i][2]), a[i][3]) == a[i][2])
				hope[2]++;
			else
				hope[3]++;
		}
		
		if (hope[1]*2<=n && hope[2]*2<=n && hope[3]*2<=n)
			cout << ag << endl;
		else if (n == 2)
		{
			ag = 0;
			int l[] = {a[1][1]+a[2][2], a[1][1]+a[2][3], a[1][2]+a[2][1], a[1][2]+a[2][3], a[1][3]+a[2][1], a[1][3]+a[2][2]};
			for (int i=0;i<6;i++)
				ag = max(ag, l[i]);
			cout << ag << endl;
		}
		else if (hope[3] == 0)
		{
			if (hope[2] == 0)
			{
				ag = 0;
				for(int i=1;i<=n;i++)
					for(int j=1;j<=i;j++)
						if (a[j][1] <= a[i][1])
							swap(a[j][1], a[i][1]);
				for(int i=1;i*2<=n;i++)
					ag += a[i][1];
				cout << ag << endl;
			}
		}
		else cout << ag << endl;
	}
	
	return 0;
}
