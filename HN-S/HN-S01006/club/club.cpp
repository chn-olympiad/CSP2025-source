#include<bits/stdc++.h>
using namespace std;
struct student
{
	int like1, like2, like3;
	bool find = false;
};
bool likecmp1(student x, student y)
{
	return x.like1 > y.like1;
};
bool likecmp2(student x, student y)
{
	return x.like2 > y.like2;
};
bool likecmp3(student x, student y)
{
	return x.like3 > y.like3;
};
bool likeallcmp1(student x, student y)
{
	return max(x.like2, x.like3) > max(y.like2, y.like3);
}
bool likeallcmp2(student x, student y)
{
	return max(x.like1, x.like3) > max(y.like1, y.like3);
}
bool likeallcmp3(student x, student y)
{
	return max(x.like2, x.like1) > max(y.like2, y.like1);
}
int main()
{
	freopen("club1.in", "r", stdin);
	freopen("club1.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		bool club1 = true, club2 = true, club3 = true;
		int n;
		cin >> n;
		long long sum1 = 0, sum2 = 0, sum3 = 0, sum = 0;
		student a[n+5];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].like1 >> a[i].like2 >> a[i].like3;
			sum1 += a[i].like1;sum2 += a[i].like2;sum3 += a[i].like3;
		}
		if(sum1 > sum2 && sum1 > sum3)
		{
			sort(a,a+n,likecmp1);
			for(int i = 0; i < n/2; i++)
			{
				sum += a[i].like1;
				a[i].find = true;
			}
			club1 = false;
		}else if(sum2 > sum1 && sum2 > sum3)
		{
			sort(a,a+n,likecmp2);
			for(int i = 0; i < n/2; i++)
			{
				sum += a[i].like2;
				a[i].find = true;
			}
			club2 = false;
		}else{
			sort(a,a+n,likecmp3);
			for(int i = 0; i < n/2; i++)
			{
				sum += a[i].like3;
				a[i].find = true;
			}
			club3 = false;
		}
		sum1 = 0, sum2 = 0, sum3 = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i].find)
			{
				a[i].like1 = 0;
				a[i].like2 = 0;
				a[i].like3 = 0;
			}
			if(!club1)
			{
				a[i].like1 = 0;
			}else if(!club2)
			{
				a[i].like2 = 0;
			}else
			{
				a[i].like3 = 0;
			}
		}
		if(!club1)
		{
			sort(a,a+n, likeallcmp1);
			for(int i = 0; i < n/2; i++)
			{
				sum += max(a[i].like2, a[i].like3);
			}
		}else if(!club2)
		{
			sort(a,a+n, likeallcmp2);
			for(int i = 0; i < n/2; i++)
			{
				sum += max(a[i].like1, a[i].like3);
			}
		}else
		{
			sort(a,a+n, likeallcmp3);
			for(int i = 0; i < n/2; i++)
			{
				sum += max(a[i].like2, a[i].like1);
			}
		}
		cout << sum;
	}
	return 0;
}
