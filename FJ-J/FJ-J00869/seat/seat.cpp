#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],b[11][11],p,id,e,f,maxn=-1,point=1,q=1,r;
	int v=n*m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == p)
		{
			if(i%n==0)
			{
				int num = i/n;
				e=num;
				if(num % 2 == 0) f=1;
				else f=n;
				cout << e << " "<<f;
			}
			else
			{
				int cnt=i/n+1;
				e=cnt;
				if(cnt%2==0)
				{
					f=n-(i%n)+1;
				}
				else f=i%n;
				cout << e << " "<<f;
			}
		}
	}
	return 0;
}
