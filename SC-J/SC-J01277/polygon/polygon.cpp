#include<bits/stdc++.h>
using namespace std;
int a[9999999];
int main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	int n,maxnn=-1;
	long long sum=0,s2=0,c2=2,k=998244353;
	cin>>n;
	long long c1=n*(n-1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxnn=max(maxnn,a[i]);
	}
	if(sum<=2*maxnn)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)cout<<"1";
	else if(maxnn==1)
	{
		for(int i=3;i<=n;i++)
		{
			c2=(c2%k)*(i%k);
			c1=((n-i+1)%k)*(c1%k);
			s2+=c1/c2;
		}
		cout<<s2%k;
	}
	return 0;
} 