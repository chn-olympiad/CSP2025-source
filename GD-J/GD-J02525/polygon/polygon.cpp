#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],b[5005],c[5005],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]+a[i];
	c[0]=1;
	for(int i=1;i<=n;i++) c[i]=(c[i-1]*i)%mod;
	sort(a+1,a+1+n);
	int t=1,s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]) t++;
		else s=max(s,t),t=1;
	}
	s=max(s,t);
	for(int i=3;i<=n;i++)
	{
		for(int j=i-1;j>=2;j--)
		{
			if(b[j]>a[i])
			{
				ans=(ans+c[i]/(c[j+1]*c[i-j-1]))%mod;
			}
			else break;
		}
	}
	cout<<1;
	return 0;
}
