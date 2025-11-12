#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int n;
int a[5001]={0};
long long ta[5001]={0};
long long ans=0;
long long jc(long long x)
{
	if(ta[x]!=0)
		return ta[x];
	ta[x]=(x*jc(x-1)%M)%M;
	return ta[x]%M;
}
void worka()
{
	if(a[0]+a[1]+a[2]>2*a[2])
		cout<<1<<endl;
	else
		cout<<0<<endl;
}
void dfss(int x,int it,long long atti)
{
	if(x==1)
	{
		if(atti>2*a[it])
			ans++;
	}
	else
	{
		for(int i=it+1;i<n;i++)
			dfss(x-1,i,atti+a[i]);
	}
	return;
}
void workb()
{
	for(int i=3;i<=n;i++)
		for(int j=0;j<n-i+1;j++)
			dfss(i,j,a[j]);
	cout<<ans<<endl;
}
void workc()
{
	long long cg=jc(n);
	for(int i=3;i<n;i++)
		ans+=(cg/(jc(n-i)*jc(i))%M)%M;
	cout<<ans+1<<endl;//why my answer is <=200??????? 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ta[0]=1;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(n==3)
		worka();
	else if(n<=20)
		workb();
	else
		workc();
	return 0;
} 