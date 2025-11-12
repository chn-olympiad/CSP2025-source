#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0;
	cin>>t;
	for(long long p=0;p<t;p++)
	{
		long long n=0,nn=0,A[4];
		long long ans=0;
		cin>>n;
		nn=n/2;
		memset(A,0,sizeof(A));
		for(long long i=0;i<n;i++)
		{
			int temp=0,temp1=0;
			for(long long j=1;j<=3;j++)
			{
				long long a=0;
				cin>>a;
				if(a>temp1&&A[j]+1<=nn)
				{
					A[j]++;
					A[temp]--;
					ans-=temp1;
					ans+=a;
					temp=j;
					temp1=a;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
