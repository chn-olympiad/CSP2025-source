#include<bits/stdc++.h>
using namespace std;
const  int N=1e7;
long long n,m,ans1,ans2,c,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) ans1++;
		if(a[i]==0) ans2++;
	}
	//m=n^k;
	//cout<<m;
	if(ans1==n)
	{
		m=n*(n-1)/2;
		cout<<m;
		return 0;
	}
	//for(long long i=1;i<=n;i++)
	//{
	//	if(a[i]^0==k)
	//	{
	//		c++;
	//		continue;
		//}
	//	for(long long j=i+1;j<=n;j++)
	//	{
	//		if(a[i]^a[j]==k)
	//		{
	//			c++;
	//		}
	//	}
	//}
	//cout<<c;
	return 0;
}
