#include<bits/stdc++.h>
using namespace std;
int a[9999999];
int main(){
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)cout<<n;
	if(k==1)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])
			{
				sum+=1;
				i+=1;
			}
			if(a[i]==a[i+1]&&a[i+2]==1&&i+2<=n)
			{
				sum+=1;
				i+=2;
			}
		}
		cout<<sum;
	}
	return 0;
} 