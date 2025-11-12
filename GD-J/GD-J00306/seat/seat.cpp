#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	} 
	int p=a[1];
	sort(a+1,a+1+n*m);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			pos=i;
			break;	
		} 	
	}
	pos=n*m-pos+1;
	int lie=ceil(pos*1.0/n);
	int hang=pos%n;
	if(hang==0) hang=n;
	if(lie%2==0)
	{
		cout<<lie<<' '<<n-hang+1;
	}
	else
	{
		cout<<lie<<' '<<hang;
	}
	
	return 0;	
} 
