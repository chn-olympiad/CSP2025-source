#include<bits/stdc++.h>
using namespace std;
int n,k,s[500010],x[500010],t,MAX,xj[500010];
long long a[500010];
void v(int p,int q,int d)
{
	if(q==n+1)
		return ;
	long long u;
	u=(d | a[q])-(d & a[q]);
	if(u==k)
	{
		t++;
		s[t]=p;
		x[t]=q;
		return ;
	}
	v(p,q+1,u);
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		v(i,i,0);
	int dog=1;
	while (dog!=0)
	{
		MAX=1;
		dog=0;
		for(int i=1;i<=t;i++)
		{
			xj[i]=0;
			for(int l=1;l<=t;l++)
				if((s[i]>=s[l] && s[i]<=x[l]) || (x[i]>=s[l] && x[i]<=x[l]))
					xj[i]++;
			if(xj[i]>MAX)
			{
				MAX=xj[i];
				dog=i;
			}
		}
		if(dog!=0)
		{
			s[dog]=s[t];
			x[dog]=x[t];
			t--;
		}
	}
	cout<<t;
	return 0;
}