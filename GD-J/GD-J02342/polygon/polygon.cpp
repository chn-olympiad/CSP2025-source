#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,ai[5005],s,t,e;
long long oplevel(int x)
{
	int f=1;
	for(int i=1;i<=x;i++) f*=i;
	return f;
}
long long opC(int p,int q)
{
	int pf=1,qf=oplevel(q);
	for(int i=q;i<=p;i++) pf*=i;
	return pf/qf;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ai[i];
	e=1;
	for(int i=1;i<=n;i++)
	{
		s=ai[i],t=1,e++;
		for(int j=n;j>0;j--) 
		{
			s+=ai[j],t++;
			if(t==e) break;
		}
		if(e>n) break;
		if(s>ai[n]*2) {ans+=opC(n,e);}
	}
	cout<<ans%998244353;
	return 0;
}
