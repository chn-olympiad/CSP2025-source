#include <bits/stdc++.h> 
using namespace std;

#define int long long

const int N = 998244353;

struct stu
{
	int s,sl;
};

stu a[10005];
int s[10005];
int l[10005];

bool cmp(stu x,stu y)
{
	return x.s > y.s;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int cur = 0;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		bool flag = 0;
		int id;
		for(int j = 1;j <= cur;j++)
		{
			if(a[j].s == x)
			{
				flag = 1;
				id = j;
			}
		}
//		cout << flag << " "; 
		if(!flag)
		{
			a[++cur].s = x;
			a[cur].sl++;
//			cout << a[cur].s << " " << a[cur].sl << "\n";
		}
		else
		{
			a[id].sl++;
//			cout << a[id].sl << "\n";
		}
	}
	sort(a + 1,a + cur + 1,cmp);
	l[0] = 1;
//	cout << "\n\n\n\n///////////\n";
//	cout << l[0] << "\n";
	for(int i = 1;i <= cur;i++)
	{
		for(int j = 1;j <= a[i].sl;j++)
		{
			s[i] = s[i - 1] + a[i].s;
		}
		l[i] = l[i - 1] * a[i].sl;
//		cout << a[i].sl << " " << s[i] << " " << l[i] << "\n";
	}
	int sum = 0;
	for(int i = 1;i <= cur;i++)
	{
		for(int j = i + 1;j <= cur;j++)
		{
			if(a[i].s * 2 < s[j])
			{
//				cout << a[i].s * 2 << " " << s[j] << "\n";
				sum += l[j] % N;
				sum %= N;
			}
		}
	}
	cout << sum % N;
	return 0;
}