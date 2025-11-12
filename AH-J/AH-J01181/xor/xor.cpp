#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans;
long long b[500001],sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  sum=sum xor a[i],b[i]=sum;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
	    if((b[i] xor b[j-1])==k)
	    {
			ans++,i=i+1,j=i+1;
			break;
		}
	cout<<ans;
	return 0;
}
