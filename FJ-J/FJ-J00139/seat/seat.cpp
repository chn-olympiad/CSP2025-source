#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c=1,r=1,t[110],j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		t[a[i]]=1;
	}
	for(int i=100;i>=a[1];i--)
		if(t[i]==1)
			j++;
	while(1)
	{
		if(j==1)
		{
			cout<<c<<" "<<r;
			return 0;
		}
		if(r==n && c%2==1)
			c++;
		else if(r!=1 && c%2==0)
			r--;
		else if(r!=n && c%2==1)
			r++;
		else if(r==1 && c%2==0)
			c++;
		j--;
	}
	return 0;
}