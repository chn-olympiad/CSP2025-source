#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],l,o=0;
bool asd(int z,int x)
{
	return z>x;
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
	l=a[1];
	sort(a+1,a+n*m+1,asd);
	for(int i=1;i<=n*m;i++)
	{ o++;
		if(a[i]==l) break;
	}	
	cout<<int(o/m+1)<<' ';
	if(int(o/m+1)%2!=0)
	{
		if(o%m!=0) cout<<o%m;
		else cout<<m;
	}
	else
	{
		if(o%m!=0) cout<<m-o%m+1;
		else cout<<1;
	}
}
