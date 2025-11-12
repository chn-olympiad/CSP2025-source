#include<bits/stdc++.h>
using namespace std;
int n,a[5001]={},s=0; 
int dg(int x1,int max_x,int s2)
{
	if(s2>a[max_x+1])
	{
		s=(s+int(pow(2,x1))%998244353)%998244353;
		return 0;
	}
	if(x1<1)return 0;
	dg(x1-1,max_x,s2+a[x1]);
	dg(x1-1,max_x,s2);
	return 0;
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
	for(int i=3;i<=n;i++)
	{
		dg(i-1,i-1,0);
	}
	cout<<s;
	return 0;	
}
