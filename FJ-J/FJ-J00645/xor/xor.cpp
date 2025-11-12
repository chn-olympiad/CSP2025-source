#include<iostream>
using namespace std;
const int maxn = 2*1e5 + 10;
int n,m[maxn],k,s;

int f(int x,int y)
{
	int q = m[x];
	for(int i =x + 1;i<=y;i++)
	{
		q = q^m[i];
	}
	return q;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int ma = -1,p=0;
	for(int i =1;i<=n;i++)
	{
		cin >> m[i];
		ma = max(ma,m[i]);
		if(m[i] == 0)
			p = 1;
	}
	if(ma == 1)
	{
		if(p == 0)
			cout << n/2;
		else if(k == 0 && p == 1) 
		{
			int s = 0;
			for(int i =1;i<=n;i++)
			{
				if(m[i] == 1&&m[i+1] == 1)
				{
					s++;
					m[i + 1] = -1;
				}
				if(m[i] == 0)
					s++;
			}
			cout <<s;
		}
		else if(k == 1 && p == 1)
		{
			int s = 0;
			for(int i =1;i<=n;i++)
			{
				if(m[i] == 0&&m[i+1] == 0)
				{
					s++;
					m[i + 1] = -1;
				}
				if(m[i] == 1)
					s++;
			}
			cout <<s;
		}
		return 0;
	}
	for(int l = 1;l<=n;l++)
	{
		for(int i = 1;i<=n-l+1;i++)
		{
			int j = i + l - 1;
			if(f(i,j) == k)
				s++;
		}
	}
	cout <<s;
	return 0;
}
