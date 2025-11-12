#include<bits/stdc++.h>
using namespace std;
struct T{
	int l,r;
}f[500005];
bool cmp(T x,T y)
{
	return x.r<y.r;
}
int ur=-11,n,k,cnt1,a[500005],b[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((b[j]^b[i-1])==k)
			{
				f[++cnt1].l=i;
				f[cnt1].r=j;
			}
		}
	}
	sort(f+1,f+cnt1+1,cmp);
	for(int i=1;i<=cnt1;i++)
	{
		if(f[i].l>ur)
		{
			ur=f[i].r;
			ans++;
		}
	}
	cout<<ans;
}
