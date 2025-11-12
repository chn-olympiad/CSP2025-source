#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,a[1000],r,l,p=1,q=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			l=i;
			break;
		}
	}
	while(q==0)
	{
		if(l<=m)
		{
			if(p%2==0)
				q=m-l+1;
			else
				q=l;
			break;
		}
		l-=m;
		p++;
	}
	cout<<p<<' '<<q;
	return 0;
}
