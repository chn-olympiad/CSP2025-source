#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,ans=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++)
	{
		cin>>b;
		if(b>a)
		ans++;
	}
	a=ans/n+1;
	if(ans/n+(ans%n)==ans/n)
	a=ans/n;
	b=ans-ans/n*n;
	if(b==0)
	{
		b=n;
	}
	if(a%2==0)
	b=n-ans+ans/n*n+1;
	cout<<a<<' '<<b; 
	return 0;
}