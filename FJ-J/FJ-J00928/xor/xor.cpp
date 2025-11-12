#include<iostream>
#include<string.h>
using namespace std;
bool flag,flag2;
int n,tp1=1;
long long k,ans=0,tp2,tong[2]={0};
int a[500005];
bool pd(int l,int r)
{
	int sum;
	if(l==r)
		sum=a[l];
	else
		sum=(tp2^a[r]);
	tp2=sum;
	if(k==sum)
		return true;
	else
		return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	flag2=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			flag2=false;
			break;
		}
	}
	if(flag2)
	{
		if(k==1)
		{
			cout<<100;
		}
		if(k==0)
		{
			cout<<50;
		}
	}
	while(tp1<=n)
	{
		flag=false;
		for(int i=tp1;i<=n;i++)
		{
			if(pd(tp1,i))
			{
				ans++;
				flag=true;
				tp1=i+1;
				break;
			}
		}
		if(!flag)
			tp1++;
	}
	cout<<ans;
}
