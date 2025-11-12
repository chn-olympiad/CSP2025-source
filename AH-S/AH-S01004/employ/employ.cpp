#include<iostream>
using namespace std;

int n;
int m;
int ans=1;
char s;
int a[505];
int patient[505];
int normal=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{
			char s;
			cin>>s;
			a[i]=int(s)-48;
		}
	for(int i=1;i<=n;i++)
	{
		cin>>patient[i];
		if(patient[i]!=0)
			normal++;
	}
	if(m==1)
	{
		for(int i=1;i<=n-1;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		ans*=normal;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
