#include<bits/stdc++.h>
using namespace std; 
int n,m,k,x;
double a[10001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			x=i;
		}
	}
    if(x%n==0)
    {
    	int h=x/n;
    	if(h%2==0)
    	{
    		cout<<h<<" "<<1;
		}
		else
		{
			cout<<h<<" "<<n;
		}
	}
	else
	{
		int h=(x/n)+1;
		if(h%2==1)
		{
			cout<<h<<" "<<x%n;
		}
		else
		{
			cout<<h<<" "<<(n+1)-(x%n);
		}
	}
}
