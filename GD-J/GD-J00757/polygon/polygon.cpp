#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
int t[5005];
long long mood(int x)
{
	long long cnt=1;
	while(x>1)
	{
		cnt=(cnt+x)%MOD;
		x--;
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
		t[a[i]]++;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int w=a[1]+a[2]+a[3];
		if(w>maxa*2) cout<<1;
		return 0;
	}
	if(maxa==0)
	{
		cout<<0;
		return 0;
	}
	if(maxa==1)
	{
		if(t[1]<3)
		{
			cout<<0;
			return 0;
		}
		long long ans=0;
		ans+=mood(t[0])*(t[1]-3+1)%MOD;
		cout<<ans;
	}
	return 0;
}
