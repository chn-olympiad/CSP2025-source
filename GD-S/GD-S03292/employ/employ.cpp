#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],mod=998244353;
long long ans;
char c[505];
bool b[501];
void dg(int x,int s)
{
	if(x==n)
	{
		if(s>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(a[i]>x-s&&c[x+1]=='1') dg(x+1,s+1);
			else dg(x+1,s);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dg(0,0);
	cout<<ans;
	return 0;
}
