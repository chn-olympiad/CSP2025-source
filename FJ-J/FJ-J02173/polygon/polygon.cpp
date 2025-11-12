#include<bits/stdc++.h>
using namespace std;
int n,a[50050];
long long k=0;
void pol(int t,int s,int l)
{
	if(t>=3)
	{
		if(s>a[l]*2)
		{
			k++;
			k%=998244353;
		}
	}
	if(t==n)return ;
	if(l==n)return ;
	for(int j=l+1;j<=n;j++)
	{
		pol(t+1,s+a[j],j);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		pol(1,a[i],i);
	}
	cout<<k;
	return 0;
	
}
