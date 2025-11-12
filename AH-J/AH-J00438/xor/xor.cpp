#include <bits/stdc++.h>
using namespace std;
long long xo(long long a,long long b)
{
	long long c=0,jia=1;
	while(a>0 || b>0)
	{
		if(a%2!=b%2)
			c+=jia;
		jia*=2;
		a/=2;
		b/=2;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans;
	long long a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			a[i]=-1;
			if(a[i]!=-1 && a[i-1]!=-1)
				a[i]=xo(a[i],a[i-1]);
		}
	}
	long long l=1,r=1;
	for(l=1;l<=n-1;l++)
	{
		
		for(r=l+1;a[r]!=-1 && r<=n;r++)
		{
			if(xo(a[l],a[r])==k)
			{
				a[l]=r;
				break;
			}
		}
		if(a[r]==-1 || r>n) a[l]=-1;
	}
	a[n]=-1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=-1)
		{
			int k=0;
			for(int j=i;j<=a[i];j++)
			{
				if(a[j]!=-1) k++;
			}
			if(k>1) a[i]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		if(a[i]!=-1) ans++;
	}
	cout<<ans;
	return 0;
}
