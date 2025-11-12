#include <bits/stdc++.h>
using namespace std;
long long n,k,s=0,f[25];
int a[500005];
int yh(int x,int y)
{
	int lc=0,ld=0,xs=0,c[25],d[25];
	while(x>0)
	{
		lc++;
		c[lc]=x%2;
		x/=2;
	}
	while(y>0)
	{
		ld++;
		d[ld]=y%2;
		y/=2;
	}
	lc=max(lc,ld);
	for(int y=1;y<=lc;y++);
	{
		if(c[y]!=d[y]) c[y]=1;
		else c[y]=0;
	}
	for(int i=1;i<=max(lc,ld);i++) xs+=c[i]*f[i];
	return xs;
}
void pd()
{
	f[1]=1;
	for(int i=1;i<=20;i++) f[i]=f[i-1]*2;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	pd();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		a[i]=yh(a[i-1],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) s++;
		else
		{
			int j=i+1;
			for(;j<=n;j++)
			{
				if(yh(a[i],a[j])==k)
				{
					s++;
					i=j+1;
					break;
				}
			}
		}
		
	}
	cout<<s;
	return 0;
}

