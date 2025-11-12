#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[5005],b[5005],c[5005],ma=-1,t,sd;
int ji(int lt,int rt)
{
	int tt=1;
	for(int i=lt;i<=rt;i++)
	{
		tt=(tt%N)*(i%N);
	}
	return tt;
}
int quanpai(int x)
{
	int tt=0;
	for(int i=1;i<x;i++)
	{
//		cout<<ji(x+1-i,x)<<" "<<ji(1,i)<<endl;
		tt=tt+(ji(x+1-i,x)/ji(1,i))%N;
	}
	return tt+1;
}
void ss(int x,int sum)
{

	if(sum>=a[sd]*2-1)
	{
		t+=quanpai(x-1);
		return;
	}
	if(x==1)
	{
		return;
	}
	
	for(int j=x-1;j>=1;j--)
	{
		ss(j,sum+a[j]);
	}
	
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(sd=n;sd>=2;sd--)
	{
		ss(sd,a[sd]);
	}
	cout<<t;
	return 0;
}
