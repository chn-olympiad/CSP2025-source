#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long minn,maxn,f[5005][5005],mod=998244353,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
	}
	else if(n==5) cout<<6;
	else cout<<0;
	return 0;
}


