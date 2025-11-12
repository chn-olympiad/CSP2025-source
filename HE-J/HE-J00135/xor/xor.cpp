#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005],ans=0,sumx[500005];
bool f[500005];

int Xor(int x,int y)
{
	string s = "$";
	while(x!=0 && y!=0)
	{
		if((x%2)!=(y%2))
		{
			s = "1" + s;
		}
		else
		{
			s = "0" + s;
		}
		x = x/2;
		y = y/2;
	}
	while(y)
	{
		if(0!=(y%2))
		{
			s = "1" + s;
		}
		else
		{
			s = "0" + s;
		}
		y = y/2;
	}
	while(x)
	{
		if(0!=(x%2))
		{
			s = "1" + s;
		}
		else
		{
			s = "0" + s;
		}
		x = x/2;
	}
	int t = 1,Xans = 0;
	for(int i=0;i<s.size() && s[i] != '$';i++)
	{
		if(s[i]=='1')
		{
			Xans += t;
		}
		t *= 2;
	}
	return Xans;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,0,sizeof(f));
	cin >> n >> k;
	int m=n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==k)
		{
			ans++;
			f[i]=1;
			m = max(i-1,n-i);
		}
	}
	sumx[1] = a[1];
	for(int i=2;i<=n;i++)
	{
		sumx[i] = Xor(a[i],sumx[i-1]);
	}

	for(int i = 2;i<=m;i++)
	{
		for(int l = 1;l<=n-i+1;l++)
		{
			int r = l+i-1;
			if(l!=1)
			{
				if(Xor(sumx[r],sumx[l-1]) == k)
				{
					bool jjj = 1;
					for(int j=l;j<=r;j++)
					{
						if(f[j])
						{
							jjj = 0;
							break;
						}
					}
					if(jjj)
					{
						ans++;
						m = max(l-1,n-r);
						for(int j=l;j<=r;j++)
							f[j] = 1;
					}
				}
			}
			else if(l == 1)
			{
				if(sumx[r] == k)
				{
					bool jjj = 1;
					for(int j=l;j<=r;j++)
					{
						if(f[j])
						{
							jjj = 0;
							break;
						}
					}
					if(jjj)
					{
						ans++;
						m = max(l-1,n-r);
						for(int j=l;j<=r;j++)
							f[j] = 1;
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}
