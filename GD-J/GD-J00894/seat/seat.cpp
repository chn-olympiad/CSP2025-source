#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,k,k2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			s++;
		}
	}
	s++;
	k=s/n;
	if(s%n!=0) k++;
	if(k%2==1)
	{
		k2=s%n;
		if(k2==0) k2=n;
	}
	else
	{
		k2=n-s%n+1;
		if(s%n==0) k2=1;
	}
	cout<<k<<" "<<k2<<endl;
	return 0;
}
