#include <bits/stdc++.h>
using namespace std;
int t,n,ans[114514];
struct s
{
	int a1,a2,a3;
}a[114514];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		int k = n / 2,y = 0,e = 0,s = 0,sum = 0,b;
		for(int i = 1;i <= n;i++)
		{
			ans[i] = 0;
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a2 == 0 && a[i].a3 == 0)
			{
				b = a[i].a1;
				y++;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n - i;j++)
			{
				if(a[j].a1 + a[j].a2 + a[j].a3 < a[j + 1].a1 + a[j + 1].a2 + a[j + 1].a3)
				{
					swap(a[j].a1,a[j + 1].a1);
					swap(a[j].a2,a[j + 1].a2);
					swap(a[j].a3,a[j + 1].a3);
				}
			} 
		}
		for(int i = 1;i <= n;i++)
		{
			if(a[i].a2 == 0 && a[i].a3 == 0) ans[i] = b;
			else if(y < k && e < k && s < k)
			{
				ans[i] = max(max(a[i].a1,a[i].a2),a[i].a3);
				if(ans[i] == a[i].a1) y++;
				else if(ans[i] == a[i].a2) e++;
				else s++;
			}
			else if(y >= k)
			{
				ans[i] = max(a[i].a2,a[i].a3);
				if(ans[i] == a[i].a2) e++;
				else s++;
			}
			else if(e >= k)
			{
				ans[i] = max(a[i].a1,a[i].a3);
				if(ans[i] == a[i].a1) y++;
				else s++;
			}
			else if(s >= k)
			{
				ans[i] = max(a[i].a1,a[i].a2);
				if(ans[i] == a[i].a1) y++;
				else e++;
			}
			sum += ans[i];
//			cout << "\n！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n";
//			cout << a[i].a1 << " " << a[i].a2 << " " << a[i].a3 << endl;
//			cout << y << " " << e << " " << s << " " << ans[i] << " " << sum;
//			cout << "\n！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n";
		}
		cout << sum << endl;
	}
	return 0; 
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
