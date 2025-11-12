#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sz=n*m;
	int a[sz+5],rc,b[sz+5],rz=0;
	for(int i=1;i<=sz;i++)
	{
		cin>>a[i];
		rc=a[1];
	}
	sort(a,a+sz+1);
	for(int i=sz;i>=1;i--)
	{
		b[sz-i]=a[i];
	}
	for(int i=0;i<sz;i++)
	{
		if(b[i]==rc)
			rz=i+1;
	}
	if(rz>=n)
	{
		cout<<rz/n+1<<" "<<rz%n+1;
	}
	else
	{
		cout<<'1'<<" "<<rz;
	}
	return 0;
}