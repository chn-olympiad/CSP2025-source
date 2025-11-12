#include<bits/stdc++.h>
using namespace std;
int a[5020];
int b[5020];
int c[5020];
int n,s,ans;
int maxx(int q,int w)
{
	int maxq;
	maxq=-1000;
	for(int i=q;i<=w;i++)
		if(a[i]>maxq)
			maxq=a[i];
	return maxq*2;
}
int summ(int q,int w)
{
	int sum;
	sum=0;
	for(int i=q;i<=w;i++)
		sum+=a[i];
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(maxx(i,j)<summ(i,j))
				s++;
	cout<<s%998244353;
	return 0;
}
