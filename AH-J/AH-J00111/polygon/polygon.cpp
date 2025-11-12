#include<bits/stdc++.h>
using namespace std;
	long long n,a[10001]={0},num=0;
long long sum(long long gen)
{
	gen=min(gen,n-gen);
	long long k=1;
	for(int i=1;i<=gen;i++)
	{
		k*=n-i+1;
		k/=i;
	}
	return k%998244353;
}
long long doit(long long log,long long max1,long long sum,long long ll)
{
	long long num=0;
	if(log==1)
	{for(int i=1;i<ll;i++)
	{
		if(sum+a[i]>max1*2)return max1-i-1;
	}
	return 0;
}
if(log>ll)return 0;
if(log==ll)return 1;
	for(int last=log;last<max1;last++)
	{
		num+=doit(log-1,max1,sum+a[last],last);
	}
	return num;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int fl=0;
	for(int i=1;i<=n;i++){cin>>a[i];
		if(a[i]!=1)fl=1;
	}
	if(fl==0)
	{for(int i=3;i<=n;i++)
	{
		num+=sum(i);
		num%=998244353;
	}
	cout<<num;
	return 0;}
	else{
		sort(a+1,a+1+n);
		for(int log=3;log<=n;log++)
		{
			num+=doit(log,n,0,n);
			num%=998244353;
		}
		cout<<num;
		return 0;
	}
	return 0;
}
