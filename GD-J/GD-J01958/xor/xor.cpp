#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool b1=1,b2=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			b1=0;
			if(a[i]!=0)
				b2=0;
		}
	}
	if(b1==1&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(b2==1&&k<=1)
	{
		if(k==0)
		{
			int sum=0; 
			for(int i=1;i<=n;i++)
				if(a[i]==0)
					sum++;
			cout<<sum;
			return 0;
		}
		else
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
					sum++;
			}
			cout<<sum;
			return 0;
		}
	}
	return 0;
}
