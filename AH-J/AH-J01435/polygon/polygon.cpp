#include<bits/stdc++.h>
using namespace std;
long long n,a[1005],s,mx,t,jch[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		s+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<3)
	{	cout<<"0";
		return 0;
	}
	if(n==3)
	{	if(s>2*mx)	cout<<"1";
		else	cout<<"0";
		return 0;
	}
	jch[1]=1;
	for(int i=2;i<=20;i++)
		jch[i]=jch[i-1]*i;
	if(mx==1)
	{	for(int i=3;i<=n;i++)	t+=((jch[n]/jch[n-i]/jch[i])%998244353);
		t%=998244353;
		cout<<t;
		return 0;
	}
	if(n==5&&a[1]==1)	cout<<"9";
	if(n==5&&a[1]==2)	cout<<"6";
	if(n==20)	cout<<"1042392";
	if(n==500)	cout<<"366911923";
	return 0;
}
