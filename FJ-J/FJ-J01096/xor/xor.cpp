#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0,last=0,anss=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=last+1;j<=i;j++)
		{
			if(i!=j)
				a[j]=a[j]^a[i];	
			if(a[j]==k)
			{
				anss++;
				last=i;
				break;
			}
		}
		
	}
	cout<<anss;
	return 0;
}

