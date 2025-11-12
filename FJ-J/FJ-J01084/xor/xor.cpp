#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int b[500010];
int main()
{
	long long n,k,i,f1,f2,s1=0,s2=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]!=0) f1=0;
		if(a[i]!=0&&a[i]!=1) f2=0;
		if(a[i]==0) s1++;
		if(a[i]==1) s2++;
	}
	if(f1!=0&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	else if(f2!=0&&k==1)
	{
		cout<<s2;
		return 0;
	}
	return 0;
}
