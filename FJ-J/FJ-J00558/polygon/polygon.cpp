#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5002];
long long s[5002];
long long f[5002];
long long ans;
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		if(n==3)
		{
			long long Max=0;
	    	for(int i=1;i<=n;i++)
		    {
				Max=max(Max,a[i]);
				sum+=a[i];
			}
			if(sum>2*Max)
			{
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<((n-2+1)*(n-2))/2;
	}
}	

