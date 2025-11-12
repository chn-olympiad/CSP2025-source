#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,flag[2000005],len,pos,ans;
struct fun
{
	long long l,r;
}p[500005];
bool cmp(fun a,fun b)
{
	if (a.r==b.r)
	{
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum^=a[i];
		if (flag[sum^k]||(sum==k))
		{
			len++;
			p[len].l=flag[sum^k]+1;
			p[len].r=i;		
		}
		flag[sum]=i;	
	}
	sort(p+1,p+1+len,cmp);
	for (int i=1;i<=len;i++)
	{
		if (p[i].l>pos)
		{
			pos=p[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
