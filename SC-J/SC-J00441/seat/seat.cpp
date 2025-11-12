#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],r,h=1,sum;
bool cmp(int _a,int _b)
{
	return _a>_b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	while(1)
	{
		for(int i=1;i<=n;i++)//枚举此行的列数
		{
			sum++;
			if(a[sum]==r)
			{
				cout<<h<<" "<<i;
				return 0;
			}
		}
		h++;
		for(int i=n;i>=1;i--)
		{
			sum++;
			if(a[sum]==r)
			{
				cout<<h<<" "<<i;
				return 0;
			}
		}
		h++;
	}
	return 0;
}