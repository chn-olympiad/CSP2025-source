#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[110],l,k,f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<s;i++)
	{
		cin>>a[i];
	}
	l=a[0];
	sort(a,a+s);
	for(int i=0;i<s;i++)
	{
		if(a[i]==l)
		{
			k=s-1-i;
			break;
		}
	}
	f=1+(k/n);
	if(f%2==1) k=k-n*(f-1)+1;
	else k=n-(k-n*(f-1));
	cout<<f<<" "<<k;
	return 0;
}
