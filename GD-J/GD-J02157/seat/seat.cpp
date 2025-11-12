#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],u,l,r,w;
bool ans(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[105],u;
	cin>>a[1];
	u=a[1];
	for(int i=n*m;i>=1;i--)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,ans);
	l=1;
	r=n*m;
	while(l<=r)
	{
		w=(l+r)/2;
		if(a[w]<=u)r=w-1;
		else l=w+1;
	}
	cout<<(l-1)/n+1<<" ";
	if(((l-1)/n+1)%2==1)
	{
		cout<<(l-1)%n+1;
	}
	else 
	{
		cout<<n-((l-1)%n+1)+1;
	}
	return 0; 
}
