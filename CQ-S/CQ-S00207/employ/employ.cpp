#include<bits/stdc++.h>
#define md 998244353
int a[1000],b[1000],c[1000],m,n;
long long int mm=0;
using namespace std;
void l(int x,int y,int z)
{
	//cout<<x<<" "<<y<<" "<<z<<endl;
	if(z>=m)
	{
		mm++;
		//cout<<endl<<x<<endl<<mm<<endl<<endl;
		return;
	}
	if(x>n)return;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
		if(b[x]==0||a[i]<=y)
		{
			//cout<<" 0 i "<<i<<" a[i] "<<a[i]<<" y "<<y<<" z "<<z<<" m "<<mm<<endl;
			c[i]=1;
			x+=1;
			y+=1;
			l(x,y,z);
			x-=1;
			y-=1;
			c[i]=0;
		}
		else
		{
			//cout<<" + i "<<i<<" a[i] "<<a[i]<<" y "<<y<<" z "<<z<<" m "<<mm<<endl;
			c[i]=1;
			x+=1;
			z+=1;
			l(x,0,z);
			x-=1;
			z-=1;
			c[i]=0;
		}
		}
		
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		b[i]=s[i]-48;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l(1,0,0);
	mm=mm%md;
	cout<<mm<<endl;
	return 0;
}
