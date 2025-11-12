#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
const int N=501;

int c[N];
ll f(int x)
{
	ll tmp=1;
	for(int i=1;i<x;i++)
	{
		tmp*=i;
		tmp%=MOD;
	}
	return tmp%MOD;
}

int main()
{
	int n,m,pers=0,M=-1,z=0;
	string p;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>p;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		M=max(c[i],M);
		if(c[i]==0) z++;
	}
	sort(c,c+n);
	for(int i=0;i<n;i++)
	{
		if(c[i]==0)
		{
			c[i]=M+1;
			z--;
			if(z==1) break;
		}
	}
	sort(c,c+n);
	for(int i=0;i<n;i++)
	{
//		cout<<c[i]<<" ";
		if(c[i]>=i && c[i]!=M+1) pers++;
	}
//	cout<<endl<<pers<<endl;
	cout<<f(pers)<<endl;
	return 0;
}
