#include <bits/stdc++.h>
using namespace std;
struct Fw
{
	int cb1, cb2, cb3;
} a[100005];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int flg[100005], n, cnt[3], sum = 0, f[100005], s[100005], t[100005], num1[100005], num2[100005], idf[100005], ids[100005], idt[100005];
		cnt[1] = cnt[2] = cnt[3] = 0;
		cin >> n;
		int fu = n / 2;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].cb1 >> a[i].cb2 >> a[i].cb3;
			if(a[i].cb1 >= a[i].cb2 && a[i].cb2 >= a[i].cb3)
			{
				f[i] = a[i].cb1;
				s[i] = a[i].cb2;
				t[i] = a[i].cb3;
				idf[i] = 1;
				ids[i] = 2;
				idt[i] = 3;
			}
			else if(a[i].cb1 >= a[i].cb3 && a[i].cb3 >= a[i].cb2)
			{
				f[i] = a[i].cb1;
				s[i] = a[i].cb3;
				t[i] = a[i].cb2;
				idf[i] = 1;
				ids[i] = 3;
				idt[i] = 2;
			}
			else if(a[i].cb2 >= a[i].cb1 && a[i].cb1 >= a[i].cb3)
			{
				f[i] = a[i].cb2;
				s[i] = a[i].cb1;
				t[i] = a[i].cb3;
				idf[i] = 2;
				ids[i] = 1;
				idt[i] = 3;
			}
			else if(a[i].cb2 >= a[i].cb3 && a[i].cb3 >= a[i].cb1)
			{
				f[i] = a[i].cb2;
				s[i] = a[i].cb3;
				t[i] = a[i].cb1;
				idf[i] = 2;
				ids[i] = 3;
				idt[i] = 1;
			}
			else if(a[i].cb3 >= a[i].cb2 && a[i].cb2 >= a[i].cb1)
			{
				f[i] = a[i].cb3;
				s[i] = a[i].cb2;
				t[i] = a[i].cb1;
				idf[i] = 3;
				ids[i] = 2;
				idt[i] = 1;
			}
			else
			{
				f[i] = a[i].cb3;
				s[i] = a[i].cb1;
				t[i] = a[i].cb2;
				idf[i] = 3;
				ids[i] = 1;
				idt[i] = 2;
			}
			num1[i] = f[i] - s[i];
			num2[i] = s[i] - t[i];
		}
		for(int i = 1; i <= n; i++)
		{
			if(cnt[idf[i]] + 1 <= fu)
			{
				sum += f[i];
				cnt[idf[i]]++;
			}
			else
			{
				int minnu = 1e9, id;
				for(int i = 1; i <= n; i++)//查找损失最小的入 
				{
					if(num1[i] <= minnu)
					{
						minnu = num1[i];
						id = i;
					}
				}
				sum += f[i];
				sum -= f[id];
				sum += s[id];
				cnt[ids[id]]++;
			}
		}
		cout << sum << endl;
	}
	return 0;//狮山代码，没招了 
}
