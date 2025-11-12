#include <bits/stdc++.h>
using namespace std;
int t, n, f[100005], num1, num2, num3, sum;
bool flag_a = true, flag_b = true, flag_c = true;
struct s
{
	int s1,s2,s3;
	int man[3];
} a[100005];

bool cmp(s x, s y)
{
	if (x.s1==y.s1)
	{
		if (x.s2==y.s2)
		{
			return x.s3 >= y.s3;
		}
		return x.s2>y.s2;
	}
	return x.s1 > y.s1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		flag_a = true, flag_b = true, flag_c = true;
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
			if (a[i].s2!=0||a[i].s3!=0)
				flag_a=false;
			if (a[i].s1!=0||a[i].s2!=0)
				flag_b=false;
			if (a[i].s1!=0||a[i].s3!=0)
				flag_c=false;
		}
		if (n == 2)
		{
			sum = max(a[1].s1+max(a[2].s2, a[2].s3), max(a[1].s2+max(a[2].s1, a[2].s3),a[1].s3+max(a[2].s1, a[2].s2)));
			cout << sum;
			continue;
		}
		if (flag_a)
		{
			sort(a+1, a+n+1, cmp);
			for (int i = 1; i <= n/2; i++)
			{
				sum += a[i].s1;
			}
			cout << sum << endl;
			continue;
		}
		if (flag_b)
		{
			sort(a+1, a+n+1, cmp);
			for (int i = 1; i <= n/2; i++)
			{
				sum += a[i].s3;
			}
			cout << sum << endl;
			continue;
		}
		if (flag_c)
		{
			sort(a+1, a+n+1, cmp);
			for (int i = 1; i <= n/2; i++)
			{
				sum += a[i].s2;
			}
			cout << sum << endl;
			continue;
		}
		sort(a+1, a+n+1, cmp);
		memset(f, 0, sizeof(f));
		num1 = 0, num2 = 0, num3 = 0;
		int pl = 0;
		for (int i = 1; i <= n; i++)
		{
			pl = 0;
			if (num1<n/2)
			{
				if (f[i-1]+a[i].s1>f[i])
				{
					pl = max(pl,f[i-1]+a[i].s1);
				}
			}
			if (num2<n/2)
			{
				if (f[i-1]+a[i].s2>f[i])
				{
					pl = max(pl,f[i-1]+a[i].s2);
				}
			}
			if (num3<n/2)
			{
				if (f[i-1]+a[i].s3>f[i])
				{
					pl = max(pl,f[i-1]+a[i].s3);
				}
			}
			f[i] = pl;
			if (pl==f[i-1]+a[i].s1)
				num1++;
			else if(pl==f[i-1]+a[i].s2)
				num2++;
			else if(pl==f[i-1]+a[i].s3)
				num3++;
		}
		cout << f[n] << endl;
		
		for (int i = 1; i <= n; i++)
		{
			a[i].s1 = a[i].s2 = a[i].s3 = 0;
		}
	}
	return 0;
}

