#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int a,b,m,n,d,e,ans=0;
	cin>>a>>b;
	e=a*b;
	int c[e];
	for(int i=0;i<=e-1;i++)
	{
		cin>>c[i];
	}
	d=c[0];
	sort(c,c+e);
	for(int i=0;i<=e-1;i++)
	{
		if(c[i]==d)
		{
			break;
		}
		else
		{
			ans++;
		}
	}
	ans=e-ans;
	if(ans%a==0)
	{
		n=ans/a;
		if(n%2==1)
		{
			m=a;
		}
		else
		{
			m=1;
		}
	}
	else
	{
		n=ans/a+1;
		if(n%2==1)
		{
			m=ans%a;
		}
		else
		{
			m=a-ans%a+1;
		}
	}
	cout<<n<<" "<<m;
	return 0; 
}
