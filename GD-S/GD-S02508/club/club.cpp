#include<bits/stdc++.h>
using namespace std;
long long T,n,a[1000009][3],ans,b[1000009],c[3],S,s[1000009],d[1000009];
long long mmax_1(long long x,long long y)
{
	if(x>y)return x;
	return y;
}
long long mmax_2(long long x)
{
	long long mx=0;
	for(int i=0;i<=2;++i)
	{
		if(b[x]!=i&&a[x][i]>mx)
		{
			mx=a[x][i];
		}
	}
	return mx;
}
void sort_(long long l,long long r)
{
	if(l>=r)return;
	long long mid=(l+r)/2;
	sort_(l,mid);
	sort_(mid+1,r);
	long long i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(s[i]>s[j])
		{
			++k;
			d[k]=s[i];
			++i;
		}
		else
		{
			++k;
			d[k]=s[j];
			++j;
		}
	}
	while(i<=mid)
	{
		++k;
		d[k]=s[i];
		++i;
	}
	while(j<=r)
	{
		++k;
		d[k]=s[j];
		++j;
	}
	for(i=0;i<k;++i)
	{
		s[i+l]=d[i+1];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	for(int t=1;t<=T;++t)
	{
		ans=0;
		for(int i=0;i<=2;++i)
		{
			c[i]=0;
		}
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			ans+=mmax_1(mmax_1(a[i][0],a[i][1]),a[i][2]);
			if(mmax_1(mmax_1(a[i][0],a[i][1]),a[i][2])==a[i][0])
			{
				b[i]=0;
				++c[0];
			}
			else if(mmax_1(mmax_1(a[i][0],a[i][1]),a[i][2])==a[i][1])
			{
				b[i]=1;
				++c[1];
			}
			else
			{
				b[i]=2;
				++c[2];
			}
		}
		S=-1;
		for(int i=0;i<=2;++i)
		{
			if(c[i]>n/2)S=i;
		}
		if(S==-1)
		{
			printf("%lld\n",ans);
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				if(S==b[i])
				{
					s[i]=mmax_2(i)-mmax_1(a[i][0],mmax_1(a[i][1],a[i][2]));
				}
				else
				{
					s[i]=-1000000000;
				}
			}
			sort_(1,n);
			for(int i=1;i<=c[S]-n/2;++i)
			{
				ans+=s[i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
