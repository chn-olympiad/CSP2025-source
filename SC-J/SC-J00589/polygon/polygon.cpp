#include<bits/stdc++.h>
using namespace std;
int n,qzh[5200],a[5200],h,ans;
int ch(int l,int m,int hz)
{
	if(l==m) return 0;
	for(int i=l+1;i<=m;i++)
	{
		if(hz+a[i]>a[m+1]) ans++;
		ch(i,m,hz+a[i]);
	}
	ans%=998244353;
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],qzh[i]=qzh[i-1]+a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--)
	{
		if(qzh[i-1]<=a[i]) continue;
		ch(0,i-1,0);
	}
	cout<<ans;
	return 0;
}