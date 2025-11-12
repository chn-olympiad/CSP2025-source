#include<bits/stdc++.h>
using namespace std;
int n,k;
struct qj{
	int l,r;
}ans[500005];
bool cmp(qj x,qj y)
{
	if(x.l==y.l)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}
int a[500005];
int s[500005];
int num=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int o=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int q=s[i-1]^s[j];
			if(q==k)
			{
				ans[o]={i,j};
				o++;
			}
		}
	}
	sort(ans+1,ans+o,cmp);
	int last=ans[1].r;
	if(o>1)
	{
		num=1;
	}
	for(int i=1;i<o;i++)
	{
		if(ans[i].r<last)
		{
			last=ans[i].r;
		}
		if(ans[i].l>last)
		{
			num++;
			last=ans[i].r;
		}
	}
	cout<<num;
	return 0;
}
