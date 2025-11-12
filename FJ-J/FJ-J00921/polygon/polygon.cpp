#include<bits/stdc++.h>
using namespace std;
const long long mod=1e17;
long long n,a[4010],answer=0;
void work(int i,long long sum,long long maxx,int l)
{
	bool fl=0;
	if(l>=3&&sum>maxx*2)answer++,fl=1;
	if(i>n)return ;
	work(i+1,sum+a[i],max(maxx,a[i]),l+1);
	if(!fl)work(i+1,sum,maxx,l);
	else work(i+1,sum,maxx,l),answer--;
	answer=(answer%mod+mod)%mod;
}
long long power(long long a,long long b)
{
	long long ress=1,tmpp=a;
	while(b)
	{
		if(b&1)ress=ress*tmpp%mod;
		tmpp=tmpp*a%mod;
		b>>=1;
	}
	return ress;
}
long long C(long long n,long long m)
{
	long long an=1,bm=1;
	for(int i=n-m+1;i<=n;i++)an=an*i%mod;
	for(int i=1;i<=m;i++)bm=bm*i%mod;
	return an/bm;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool fl=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(fl==1)
	{
		long long answer=0;
		for(int m=3;m<=n;m++)answer=(answer+C(n,m)%mod+mod)%mod;
		cout<<answer;
		return 0;
	}
	work(1,0,0,0);
	cout<<answer;
	return 0;
}
