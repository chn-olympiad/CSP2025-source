#include <bits/stdc++.h>
using namespace std;

int a[10086][10086],b[10086];
int n,m;
int y,grade,s1,c,r,s2,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>grade;
		b[i]=grade;
	}
	s2=b[0];
	for(int i=0;i<m*n;i++)
	{
		for(int j=0;j<n*m-1;j++)
		{
			if(b[j]<b[j+1])
			swap(b[j],b[j+1]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==s2)
		{
			x=i+1;
			break;
		}
	}
	c=x/m+x%m;
	r=x%m;
	if(x%n==0)
	{
		r=n;
		c=x/m;
	}
	if(x%n!=0)
	{
		c=x/n+1;
		r=x%n;
	}
	cout<<r<<" "<<c<<" "<<x;
	return 0;
}

