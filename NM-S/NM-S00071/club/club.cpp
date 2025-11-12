#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,b[4],f[100010][4],s,z,o[3],p;
void h(long long x)
{
	int c;
	if(x>m)
	{
		return;
	}
	for(int k=1;k<=3;k++)
	{
		if(o[k]>=m/2)
		{
			return;
		}
		if(o[k]<m/2)
		{
			s+=f[x][k];
			o[k]++;
			
			c=1;
			//cout<<o[k];
		}
		z=max(z,s);
		//cout<<"t"<<z<<" "<<s<<" "<<o[k]<<endl;
		h(x+1);
		if(c==1)
		{
			s-=f[x][k];
			o[k]--;
			c=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%lld%lld%lld",&f[j][1],&f[j][2],&f[j][3]);
		}
		z=0;
		s=0;
		o[1]=o[2]=o[3]=0;
		p=0;
		h(1);
		cout<<z<<endl;
	}
	return 0;
}
