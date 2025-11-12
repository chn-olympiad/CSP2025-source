#include<bits/stdc++.h> 
using namespace std;
bool cmi(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmi);
	int ans=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
			ans=i;
	}
	int p=ans%m,s=(ans/m)+1;
	if(p==0)
	{
		p=n;
		s-=1;
	}
	if(s%2==0)
		p=n+1-p;
	cout<<s<<" "<<p;
	return 0; 
}
