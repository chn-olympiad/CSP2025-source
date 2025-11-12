#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long jc(long long q)
{
	int s=a[1],t=0;
	for(int i=2;i<=n;i++)
	{
		if(s==k)
			t++,s=a[i];
		else
			if(s>k)
			{
				if(s==a[i-1])
					s=a[i];
				else
					return false;
			}
			else
			{
				s=s^a[i];
			}
		
	}
	if(s==k)
		t++;
	return t;
}
long long find()
{
	int l=1,r=n,mid,kx=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(jc(mid)>=mid)
			kx=mid,l=mid+1;
		else
			r=mid-1;
	}
	return kx;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d",find());
	return 0;
} 