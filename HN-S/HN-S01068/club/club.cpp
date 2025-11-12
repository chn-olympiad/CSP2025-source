#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a1, a2, a3;
}a[100010];

int n;
long long ans;
node s1[50010], s2[50010], s3[50010];

bool cmp1(node x, node y)
{
	int xx = x.a1 - y.a1, yy = x.a2 - y.a2;
	if(xx > yy) return true;
	else if(xx < yy) return false;
	else return x.a1 > y.a1;
}
bool cmp2(node x, node y)
{
	int xx = x.a2 - y.a2, yy = x.a3 - y.a3;
	if(xx > yy) return true;
	else if(xx < yy) return false;
	else return x.a2 > y.a2;
}
bool cmp3(node x, node y)
{
	int xx = x.a3 - y.a3, yy = x.a1 - y.a1;
	if(xx > yy) return true;
	else if(xx < yy) return false;
	else return x.a3 > y.a3;
}

int main()
{
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t, k1, k2, k3;
	cin >> t;
	while(t--)
	{
		ans = 0;
		k1 = k2 = k3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a1 == a[i].a2 && a[i].a1 == a[i].a3) ans += a[i].a1;
			else if(a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) s1[++k1] = a[i];
			else if(a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3) s2[++k2] = a[i];
			else if(a[i].a3 >= a[i].a1 && a[i].a3 >= a[i].a2) s3[++k3] = a[i];
		}
		
		if(k1 > n / 2)
		{
			sort(s1 + 1, s1 + k1 + 1, cmp1);
			for(int i = n / 2 + 1; i <= k1; i++)
			{
				s2[++k2] = s1[i];
			}
			k1 = n / 2;
		}
		if(k2 > n / 2)
		{
			sort(s2 + 1, s2 + k2 + 1, cmp2);
			for(int i = n / 2 + 1; i <= k2; i++)
			{
				s3[++k3] = s2[i];
			}
			k2 = n / 2;
		}
		if(k3 > n / 2)
		{
			sort(s3 + 1, s3 + k3 + 1, cmp3);
			for(int i = n / 2 + 1; i <= k3; i++)
			{
				s1[++k1] = s3[i];
			}
			k3 = n / 2;
		}
		
		for(int i = 1; i <= k1; i++)
			ans += s1[i].a1;
		for(int i = 1; i <= k2; i++)
			ans += s2[i].a2;
		for(int i = 1; i <= k3; i++)
			ans += s3[i].a3;
			
		cout << ans << "\n";
	}
	
	return 0;	
}
