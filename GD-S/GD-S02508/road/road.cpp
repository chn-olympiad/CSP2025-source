#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000009],b[1000009],c[1000009],aa[1000009],bb[1000009],cc[1000009],fa[1000009],size_[1000009],ans,d[1000009],len;
void sort_(long long l,long long r)
{
	if(l>=r)return;
	long long mid=(l+r)/2;
	sort_(l,mid);
	sort_(mid+1,r);
	long long i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(c[i]<c[j])
		{
			++k;
			aa[k]=a[i];
			bb[k]=b[i];
			cc[k]=c[i];
			++i;
		}
		else
		{
			++k;
			aa[k]=a[j];
			bb[k]=b[j];
			cc[k]=c[j];
			++j;
		}
	}
	while(i<=mid)
	{
		++k;
		aa[k]=a[i];
		bb[k]=b[i];
		cc[k]=c[i];
		++i;
	}
	while(j<=r)
	{
		++k;
		aa[k]=a[j];
		bb[k]=b[j];
		cc[k]=c[j];
		++j;
	}
	for(i=0;i<k;++i)
	{
		a[i+l]=aa[i+1];
		b[i+l]=bb[i+1];
		c[i+l]=cc[i+1]; 
	}
}
long long find(long long x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge_(long long x,long long y)
{
	long long z=find(x),w=find(y);
	if(z==w)return;
	if(size_[z]<size_[w])
	{
		fa[z]=w;
		size_[w]+=size_[z];
	}
	else
	{
		fa[w]=z;
		size_[z]+=size_[w];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	}
	sort_(1,m);
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		size_[i]=1;
	}
	for(int i=1;i<=m;++i)
	{
		if(find(a[i])!=find(b[i]))
		{
			++len;
			d[len]=i;
			ans+=c[i];
			merge_(a[i],b[i]);
		}
	}
	if(k==0)
	{
		printf("%lld",ans);
	}
	else
	{
		printf("0");
	}
	return 0;
}
