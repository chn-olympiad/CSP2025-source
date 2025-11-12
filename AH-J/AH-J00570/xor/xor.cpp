#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005];
int cnt=0;
void f(int l,int r,int y)
{
	int o=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==-1)
		{
			f(i+1,r,y);
			f(l,i-1,y);
			return ;
		}
		o=a[i]^o;
		if(o==k)
		{
			for(int i=l;i<=r;i++)
			{
				a[i]=-1;
			}
			cnt++;
			f(r+1,b[y]-1,y);
			f(b[y-1],r-1,y);
			return ;
		}
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			cnt++;
			b[cnt]=i;
			a[i]=-1;
		}
	}
	b[cnt+1]=n+1;
	b[0]=1;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
		{
			f(p,b[i]-1,i);
			p=b[i]+1;
		}
	}
	cout<<cnt;
	return 0;
}
