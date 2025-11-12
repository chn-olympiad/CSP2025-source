#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],aa,w;
bool q(int d,int f)
{
	return d>f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+1+n*m,q);
	for(int i=1;i<=n*m;i++)
	{
		if(aa==a[i])
		{
			w=i;
			break;
		}
	}
	int r=w/n,c;
	w=w%n;
	if(w>0)
	{
		r++;
	}
	if(w==0)
	{
		w+=n;
	}
	if(r%2==1)
	{
		c=w;
	}
	else
	{
		c=n-w+1;
	}
	cout<<r<<" "<<c;
	return 0;
} 