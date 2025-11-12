#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,k,a[N],s[N],f[N],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	s[0]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int p=i;
		f[i]=0;
		for(int j=1;j<=i;j++)
		{
			if((s[i]^s[j-1])==k)
			{
				p=j;
				f[i]=1;
			}
		}
		int q=f[i];
		for(int j=1;j<p;j++)
		 f[i]=max(f[i],q+f[j]);
		ans=max(f[i],ans);
	}
	cout<<ans;
	return 0;
}
