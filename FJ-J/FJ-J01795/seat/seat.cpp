#include<bits/stdc++.h>
using namespace std;
bool f(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200];
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	int r;
	sort(a+1,a+1+n*m,f);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==t)
		{
			r=i;
		}
	}
	int l=(r-1)/n+1;
	int h=r%n;
	if(l%2==1)
	{
		if(h==0)
		{
			h=n;
		}
		cout<<l<<" "<<h<<endl;
		return 0;
	}
	else
	{
		if(h==0)
		{
			h=n;
		}
		h=1+n-h;
		cout<<l<<" "<<h<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
