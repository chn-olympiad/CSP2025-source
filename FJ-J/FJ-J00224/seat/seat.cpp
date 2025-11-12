#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x=1,y=1,b;
ll read()
{
	ll a=0;char b=getchar();
	for(;b>'9'||b<'0';b=getchar());
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a;
}
struct nd{
	int name;
	int tot;
}a[10000];
void cmp()
{
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[i].tot<a[j].tot)
			{
				swap(a[i].name,a[j].name);
				swap(a[i].tot,a[j].tot);
			}
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++) a[i].name=i,a[i].tot=read();
	cmp();
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].name==1) 
		{
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		if(y==1&&i!=1&&x%2==0) x++,b=0;
		else if(y==m&&x%2==1) x++,b=1;
		else if(b==1) y--;
		else y++;
	}
	return 0;
}