#include<bits/stdc++.h>
using namespace std;
int a[5002];
long long sum=0;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+1+n);
for(int i=1;i<=n-2;i++)
{
	for(int j=i+2;j<=n;j++)
	{
		int h=0;
		for(int k=i;k<=j;k++)
		{
			h+=a[k];
		}
		if(h>a[j]*2)
		{
			sum++;
			cout<<i<<' '<<j<<endl;
		}
		sum=sum%998;
		sum=sum%244;
		sum=sum%353;
	}
	
}
cout<<sum;
	return 0;
}
