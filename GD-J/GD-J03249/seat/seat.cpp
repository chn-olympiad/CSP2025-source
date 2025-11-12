#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[1010],wz;
int zd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++)
	cin>>a[i];
	sort(a+1,a+1+n*m,zd);
	for(int i=1;i<=n*m;i++)
	if(a[i]==s)
	{
		wz=i;
		break;
	}
	int ls=wz/n;
	int hs=wz%n;
	if(wz%n)
	ls++;
	cout<<ls<<" ";
	if(ls%2==1)
	{
		if(hs==0)
		cout<<n;
		else
		cout<<hs;
	}
	else
	{
		if(hs==0)
		cout<<"1";
		else
		cout<<n-hs+1;
	}
	return 0;
}
