#include<bits/stdc++.h>
using namespace std;
int n,a[5000],ma=0,s,ss;
long long sum,kk=0,kkk=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		s+=a[i];
		if(a[i]==1)
		ss++;
	}
	if(s>2*ma&&n==3)
	cout<<1;
	else if(n==3) cout<<0;
	else if(n==ss)
	{
		for(int i=1;i<=n-2;i++)
		{
			kkk+=i;
			kk+=kkk;
			sum+=kk;
		}
		cout<<sum%998244353;
	}
	return 0;
}//3 1+2+3 +1+2  +1
//4 +1+2 +1  5 +1
//1+2+3+4 +1+2+3 +1+2 +1  35
//1+2+3+4+5 1+2+3+4 +1+2+3 +1+2 +1
