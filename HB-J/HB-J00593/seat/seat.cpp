#include <bits/stdc++.h>
using namespace std;
int n,m;
int cj[102];
bool cmp(int x,int y)
{
	if(x>y)return true;
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int yz;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>cj[i];
		if(i==1)yz=cj[i];
	}
	sort(cj+1,cj+(n*m)+1,cmp);
	int z=1;
	while(cj[z]!=yz)z++;
	int c=(z+n-1)/n;
	cout<<c<<" ";
	if(c%2==0)
	{
		if(z%n==0)cout<<1;
		else cout<<n-(z%n)+1;
	}
	else
	{
		if(z%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<z%n;
		}
	}
	return 0;
}
