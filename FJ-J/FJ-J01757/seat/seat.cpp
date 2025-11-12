#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	//cout<<r<<endl;
	int l,h;
	if(r%n==0)
		l=r/n;
	else
		l=r/n+1;
	if(l%2==1)
	{
		if(r%n==0)
		{
			h=n;
		}
		else
		{
			h=r%n;
		}
	}
	else
		h=n+1-(r/l);
	cout<<l<<" "<<h;
	return 0;
}
