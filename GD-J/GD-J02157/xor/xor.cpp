#include<bits/stdc++.h>
using namespace std;
un(int x,int y)
{
	int ans=0,sum=0,w=0;
	while(x>0||y>0)
	{
		if(x%2!=y%2)ans=ans*2+1;
		else ans*=2;
		x/=2;
		y/=2;
		sum++;
	}
	for(int i=1;i<=sum;i++)
	{
		w=w*2+ans%2;
		ans/=2;
	}
	return w;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005],b[100005],sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=un(a[i],b[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(un(b[i],b[j])==k)sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
