#include<bits/stdc++.h>
using namespace std;

int a[108];
int n,m;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	} 
	
	int a1=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	int a1i;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
			a1i=i;
	}
	
	int c,r;
	c=a1i/n;
	r=a1i%n;
	if(r!=0)
		c++;
	else
		r=n;
		
	if(c%2==0)
		r=n-r+1;
	
	
	cout<<c<<" "<<r;
	
	return 0;
} 
