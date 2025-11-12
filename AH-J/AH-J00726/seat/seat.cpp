#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	float c;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			c=i;
		}
	}
	int l=ceil(c/n);
	int h;
	cout<<l;
	if(l%2==1)
		h=c-(l-1)*n;
	else
		h=n-(c-(l-1)*n)+1;
	cout<<" "<<h;
}
