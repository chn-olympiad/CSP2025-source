#include<bits/stdc++.h>
using namespace std;
int ans,n,k,f[1000010],s,num,e=1,fl;
bool v[1000100];
void xo(int a,int b)
{
	int x[100010],y[100010],z[100010];
	int t=a,p=b,u=0,o=0;
	ans=0;
	while(t>0)
	{
		x[u]=t%2;
		t/=2;
		u++;
	}
	while(p>0)
	{
		y[o]=p%2;
		p/=2;
		o++;
	}
	for(int i=0;i<max(u,o);i++)
		if(x[i]==y[i])
			z[i]=0;
		else
			z[i]=1;
	for(int i=0;i<max(u,o);i++)
		ans+=(pow(2,i)*z[i]);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]==k)
		{
			s++;
			v[i]=true;
		}	
	}
	for(int j=1;j<n;j++)
	{
		for(int l=1;l<=n;l++)
		{
			if(v[l]==true)
				continue;
			num=f[l];
			if((l+e)>n)
				break;
			if(v[l+e]==true)
			{
				l=l+e+1;
				continue;
			}
			for(int r=l+1;r<=l+e;r++)
			{
				if(v[r]==true)
				{
					fl=1;
					l=l+e+1;
					break;	
				}
				xo(num,f[r]);
				num=ans;	
			}
			if(num==k&&fl!=1)
			{
				for(int i=l;i<=l+e;i++)
					v[i]=true;
				s++;
			}
			fl=0;	
		}
		e++;	
	}
	cout<<s;	
	return 0;
}
