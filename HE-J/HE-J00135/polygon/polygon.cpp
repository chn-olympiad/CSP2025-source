#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;
int n,m,sum=0,maxx=-1,ans=0;
int a[5005];

struct Stick{
	int s;//×Ü³¤¶È
	bool f[5005];
	
};

vector<Stick> s;

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	
	if(n<3)
	{
		cout << 0;
		return 0;
	}
	else if(n==3)
	{
		cout << 1;
		return 0;
	}
	else if(maxx == 1)
	{
		cout << n-2;
		return 0;
	}
	
	while(1)
	{
		int x;
		for(int i=1;i<=n;i++)
		{
			sum += a[i];
			if(maxx < a[i])
			{
				maxx = a[i];
				x = i;
			}
		}
		if(maxx*2 >= sum)
		{
			a[x] = 0;
			n--;
		}
		else
		{
			break;
		}
	}
	sort(a+1,a+1+n,cmp);
	
	for(int j1=1;j1<=n-2;j1++)
	{
		for(int j2 = j1;j2<=n-1;j2++)
		{
			for(int j3 = j2;j3<=n;j3++)
			{
				if((a[j1]+a[j2]+a[j3]) <= max(a[j1],max(a[j2],a[j3])))
				{
					break;
				}
				else
				{
					Stick p;
					p.s = a[j1]+a[j2]+a[j3];
					memset(p.f,0,sizeof(p.f));
					p.f[j1] = 1;
					p.f[j2] = 1;
					p.f[j3] = 1;
					s.push_back(p);
					ans++
				}
			}
		}
	}
	for(int i=0;i<=s.size();i++)
	{
		for(int j=1;j<=n;j+)
	}
	cout << ans;
	return 0;
}
