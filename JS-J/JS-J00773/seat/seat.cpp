#include<bits/stdc++.h>
using namespace std;
int n,m,ma[110],ans,c=1,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>ma[i];
	}
	ans=ma[1];
	sort(&ma[1],&ma[n*m+1]);
	for(int i=n*m;i>0;i--)
	{
		if(ma[i]==ans)
		{
			cout<<r<<" "<<c;
		}
		if(r/n%2==0)
		{
			c++;
		}
		else
		{
			c--;
		}
		if(c<1)
		{
			c=1;
			r++;
		}
		if(c>n)
		{
			c=n;
			r++;
		}
	}	
	fclose(stdin);
	fclose(stdout);
}
