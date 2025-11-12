#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],r,t,l=1,s=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			t=i;
			break;
		}
	}
	while(--t)
	{
		if(l%2==1)
		{
			s++;
		}
		if(l%2==0)
		{
			s--;
		}
		if(s>n)
		{
			l++;
			s=n;
		}
		if(s<1)
		{
			l++;
			s=1;
		}
	}
	cout<<l<<" "<<s;
	return 0;
}
