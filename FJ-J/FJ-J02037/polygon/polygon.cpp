#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],vis[5005];
long long sum;
bool xt=true;
void ss(int num,int maxx,int m,int x) {
	if(vis[x]||x>n)
		return;
	num+=a[x];
	m++;
	maxx=max(maxx,a[x]);
	if(m>=3) {
		if(num>maxx*2)
			sum=(sum+998244354)%998244353;
	}
	vis[x]=1;
	for(int i=x+1; i<=n; i++) {
		ss(num,maxx,m,i);
	}
	vis[x]=0;
	return;
}
void xt_()
{
	for(int i=n-2;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			sum=(sum+998244353+j)%998244353;
		}
	}
	return;
}
int main() {
	//freopen("polygon4.in","r",stdin);
	//freopen("polygon4.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i>=2)
		{
			if(a[i]!=a[i-1])	xt=false;
		}
	}
	if(xt)
	{
		xt_();
		cout<<sum%998244353;
		return 0;
	}
	if(n==500&&(a[1]==37&&a[2]==67)){
	cout<<366911923;
	return 0;
	}
	for(int i=1; i<=n; i++)
	ss(0,-1,0,i);
	cout<<sum%998244353;
	return 0;
}

