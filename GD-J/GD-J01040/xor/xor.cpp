#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,a[200005],k,b=0;
struct ct{
	int s;
	int f;
}st[200005];
bool cmp(ct pre,ct nxt)
{
	if(pre.f==nxt.f) return pre.f-pre.s<nxt.f-nxt.s;
	else return pre.f<nxt.f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int w=0;
		for(int j=i;j<=n;j++)
		{
			w=w^a[j];
			if(w==k)
			{
				b++;
				st[b].s=i;
				st[b].f=j;
				break;
			}
		}
	}
	sort(st+1,st+1+b,cmp);
	int z=0;
	for(int i=1;i<=b;i++)
	{
		if(st[i].s>z)
		{
			sum++;
			z=st[i].f;
		}
	}
	cout<<sum;
}
