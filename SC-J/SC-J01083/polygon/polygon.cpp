#include<bits/stdc++.h>
using namespace std;
int n,a[5010],q[5010],w[5010],b[5010];
long long h;
void jq(int l,int r,int z)
{
//	cout<<z<<"\n";
//	cout<<l<<" "<<r<<"\n";
	if(z>0)
	{
		h++;
		h=h%998244353;
	}
	else
	{
		return;
	}
	for(int i=l;i<=r;i++)
	{
		if(b[a[i]]!=0)
		{
			b[a[i]]-=1;
			jq(i+1,r,z-a[i]);
//			cout<<"\n";
			b[a[i]]+=1;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[a[i]]+=1;
		q[i]=a[i]+q[i-1];
		w[i]=a[i]*2;
	}
	for(int i=3;i<=n;i++)
	{
		if(q[i]>w[i])
		{
			jq(1,i-1,q[i]-w[i]);
		}
	}
	cout<<h;
	return 0;
} 