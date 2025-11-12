#include<bits/stdc++.h>
using namespace std;
bool dy(int x,int y)
{
	return x>y;
}
bool xy(int x,int y)
{
	return x<y;
}
int a[105],s[11][11],x=1;
int x1[11],x2[11],x3[11],x4[11],x5[11],x6[11],x7[11],x8[11],x9[11],x10[11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m,dy);
	for(int i=1;i<=n;i++)
	{
		x1[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		x2[i]=a[2*n+1-i];
	}
	for(int i=1;i<=n;i++)
	{
		x3[i]=a[2*n+i];
	}
	for(int i=1;i<=n;i++)
	{
		x4[i]=a[4*n+1-i];
	}
	for(int i=1;i<=n;i++)
	{
		x5[i]=a[4*n+i];
	}
	for(int i=1;i<=n;i++)
	{
		x6[i]=a[6*n+1-i];
	}
	for(int i=1;i<=n;i++)
	{
		x7[i]=a[6*n+i];
	}
	for(int i=1;i<=n;i++)
	{
		x8[i]=a[8*n+1-i];
	}
	for(int i=1;i<=n;i++)
	{
		x9[i]=a[8*n+i];
	}
	for(int i=1;i<=n;i++)
	{
		x10[i]=a[10*n+1-i];
	}
	for(int i=1;i<=n;i++)
	{
		if(x1[i]==ans)
		{
			cout<<1<<" "<<i;
			break;
		}
		if(x2[i]==ans)
		{
			cout<<2<<" "<<i;
			break;
		}
		if(x3[i]==ans)
		{
			cout<<3<<" "<<i;
			break;
		}
		if(x4[i]==ans)
		{
			cout<<4<<" "<<i;
			break;
		}
		if(x5[i]==ans)
		{
			cout<<5<<" "<<i;
			break;
		}
		if(x6[i]==ans)
		{
			cout<<6<<" "<<i;
			break;
		}
		if(x7[i]==ans)
		{
			cout<<7<<" "<<i;
			break;
		}
		if(x8[i]==ans)
		{
			cout<<8<<" "<<i;
			break;
		}
		if(x9[i]==ans)
		{
			cout<<9<<" "<<i;
			break;
		}
		if(x10[i]==ans)
		{
			cout<<10<<" "<<i;
			break;
		}
	}
	return 0;
	}
