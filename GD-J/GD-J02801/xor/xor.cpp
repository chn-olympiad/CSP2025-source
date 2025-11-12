#include<bits/stdc++.h>
using namespace std;
struct data
{
	int l,r;
};
vector<data>v;
bool cmp(data x,data y)
{
	if(x.l==y.l)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}
int n,K,s;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int e=a[j-i+1];
			for(int k=j-i+2;k<=j;k++)
			{
				e^=a[k];
			}
			if(e==K)
			{
				v.push_back({j-i+1,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int len=v.size(),r=v[0].r;
	if(len-1)
	{
		s=1;
	}
	for(int i=1;i<len;i++)
	{
		if(v[i].l>r)
		{
			s+=1;
			r=v[i].r;
		}
	}
	printf("%d",s);
	return 0;
}
