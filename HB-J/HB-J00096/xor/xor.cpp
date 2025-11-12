#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct nf
{
	int l,r=-1;
}len[500005];
bool cmp(nf x,nf y)
{
	return x.r<=y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int num=a[i],j=i;
		while(num!=k&&j<=n)
		{
			j++;
			num^=a[j];
		}
		len[i].l=i;
		len[i].r=j;
		if(num!=k)
		{
			len[i].r=-1;
		}
	}
	sort(len+1,len+n+1,cmp);
	int stt=1;
	if(len[n].r==-1)
	{
		cout<<0;
		return 0;
	}
	while(len[stt].r==-1&&stt<=n)
		stt++;
	int last=len[stt].r;
	int ans=1;
	for(int i=stt+1;i<=n;i++)
	{
		if(len[i].l>last)
		{
			last=len[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
