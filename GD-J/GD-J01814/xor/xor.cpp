#include<bits/stdc++.h>
using namespace std;
const int M=1e5+100;
int n,m,sum[M],a[M],f[M],k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sum[1]=a[1];
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]^a[i];
	if(k<=1)
	{
		for(int i=1;i<=n;i++)if(a[i]==k)ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<i;j++){
			int p=sum[i]^sum[j];
			if(p==k)f[i]=max(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	return 0;
}
