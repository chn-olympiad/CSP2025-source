#include <bits/stdc++.h>
using namespace std;
long long n,k,temp,sum[500005],num,ans; 
struct node
{
	int l,r;
}a[500005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		if(i==1)
			sum[i]=temp;
		else
			sum[i]=sum[i-1]^temp;
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((sum[j]^sum[i-1])==k)
			a[++pos].l=i,a[pos].r=j;
		}
	}
	if(pos==0)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+pos+1,cmp);
	int r=a[1].l-1;
	for(int i=1;i<=pos;i++)
	{
		if(a[i].l>r)
		{
			r=a[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
