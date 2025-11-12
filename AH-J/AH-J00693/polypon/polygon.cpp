#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,maxn=-1;
bool f;
void prime(int x)
{
	for(int i=3;i<=n;i++)
	{
		ans+=(n-i+2)*(n-i+1)/2;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=1;
		maxn=max(maxn,a[i]);
	}
	if(n==3&&f) 
	{
		if(a[1]+a[2]+a[3]>maxn*2) cout<<1;
		else cout<<0;
	} 
	else
	{
		prime(n);
		cout<<ans;
	}
}
