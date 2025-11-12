#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,c,ww1,ww2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++)
	{
		cin>>b;
		if(b>a)
		c++;
	}
	c++;
	cout<<(c+m-1)/m<<" ";
	ww1=c%m;
	ww2=(c+m-1)/m;
	if(ww1==0)
	ww1=m;
	if(ww2%2==0)
	{
		cout<<n-ww1+1;
	}
	else
	cout<<ww1;
	return 0;
}
