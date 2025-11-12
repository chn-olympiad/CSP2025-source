#include<bits/stdc++.h>
using namespace std;
const int M=5e6+5;
const int N=2e5+5;
char a[M],b[M],c[M],d[M];
int n,q,x[N],y[N],z[N],ans;
int l,r,u;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		x[i]=strlen(a);
		for(int j=0;j<x[i];j++)
		{
			if(a[j]=='b')
			{
				y[i]=j;
				break;
			}
		}
		for(int j=0;j<x[i];j++)
		{
			if(b[j]=='b')
			{
				z[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>c>>d;
		u=strlen(c);
		for(int j=0;j<u;j++)
		{
			if(c[j]=='b')
			{
				
				l=j;
				break;
			}
		}
		for(int j=0;j<u;j++)
		{
			if(d[j]=='b')
			{
				r=j;
				break;
			}
		}
		//cout<<l<<" "<<r;
		for(int j=1;j<=n;j++)
		{
			if(x[j]-y[j]-1<=u-l-1&&l>=y[j]&&u>=x[j])
			{
				if((l-r)==y[j]-z[j])
				{
					ans++;
					
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
