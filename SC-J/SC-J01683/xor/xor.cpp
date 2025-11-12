#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005];
struct st{
	int l,r;
}ans[1000005]; 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=1,num0=0,num1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)	b[i]=a[i];
		else	b[i]=(b[i-1]^a[i]);
		if(a[i]==0)	num0++;
		if(a[i]==1)	num1++;
	}
	if(n>1000&&k==1&&num1+num0==n)
	{
		cout<<num1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[i-1]^b[j])==k)
				ans[m].l=i,ans[m].r=j,m++;
	m--;
	int sum=1,x=ans[m].l;
	for(int i=m-1;i>=1;i--)
		if(ans[i].r<x)
		{
			sum++;
			x=ans[i].l;
		}
	cout<<sum;
	return 0;
} 