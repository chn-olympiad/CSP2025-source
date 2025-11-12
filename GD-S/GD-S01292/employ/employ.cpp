#include<bits/stdc++.h>
using namespace std;
long long n,m,t=0,ans=0;
long long sj[100],nx[100],p[100];
char str[100];
bool cc(long long pd,long long wz)
{
	bool jg=true;
	for(long long i=0;i<wz;i++)
	{
		if(p[i]==pd)
		{
			jg=false;
			break;
		}
	}
	return jg;
}
void dps(long long wz,long long lq)
{
	if(wz==n)
	{
		if(lq>=m)ans=(ans+1)%998244353;
	}
	else if(wz<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(cc(i,wz))
			{
				p[wz]=i;
				if(nx[i]>(wz-lq))
				{
					dps(wz+1,lq+sj[wz+1]);
				}
				else dps(wz+1,lq);
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	while(cin>>str[++t]&&t<n);
	for(long long i=1;i<=n;i++)
	{
		sj[i]=str[i]-'0';
		cin>>nx[i];
	}
	dps(0,0);
	cout<<ans;
	return 0;
}
