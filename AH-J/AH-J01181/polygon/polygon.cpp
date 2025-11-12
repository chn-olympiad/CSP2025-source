#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans=0;
const long long mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=pow(2,n)-1;i++)
	{
		int tmp=i,b[n+1],k=0,sum=0,maxn=0;
		for(int j=1;j<=n;j++)
		  b[j]=0;
		while(tmp!=0)
		{
			b[++k]=tmp%2;
			tmp/=2;
		}
		for(int j=1;j<=n;j++)
		{
		  if(b[n-j+1]==1)
		  {
			  sum+=a[j];
			  if(a[j]>maxn)maxn=a[j];
		  }
	    }
	    if(sum>maxn*2)ans++;
	      ans%=mod;
	}
	cout<<ans;
	return 0;
}
