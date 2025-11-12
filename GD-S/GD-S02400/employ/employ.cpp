#include<bits/stdc++.h>
using namespace std;
long long sum;
int a[100005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string tf;
	cin>>tf;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int t=0,z=1,k=n;
	while(t>=a[z])
	{
		t++;
		z++;
		k--;
	}
	long long sum=0;
	for(int i=1;i<=k-m+1;i++)
	{
		long long num=1;
		for(int j=k;j>=k-i+1;j--)
		{
			num*=j;
			num%=998244353;
		}
		sum+=num;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
} 
