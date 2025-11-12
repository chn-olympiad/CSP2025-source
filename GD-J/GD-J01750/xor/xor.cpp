#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=500005,maxm=4005;
ll n,k,a[maxn],f[maxn],flag=0,flaga=1,flagb=1;
inline void fre()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
inline void caseA()
{
	if(k==1)
	{
		cout<<n;
		return; 
	}
	else if(!k)
	{
		cout<<n/2;
		return;
	}
	cout<<0;
}
inline void caseB()
{
	ll ans=0;
	if(k>1) 
	{
		cout<<0;
		return;
	}
	if(k==1)
	{
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]!=a[i+1]) i++,ans++;
			else if(a[i]) ans++;	
		}
		if(a[n]&&a[n-1]==a[n]) ans++;
		cout<<ans;
		return;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]&&a[i+1]) i++,ans++;
		else if(!a[i]) ans++;
	}
	if(!a[n]) ans++;
	cout<<ans;
}
inline void teshu()
{
	if(flaga)
	{
		caseA();
		flag=1;
		return;
	} 
	if(flagb)
	{
		caseB();
		flag=1;
		return;
	}
}
int main()
{
	IOS
	fre();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flaga=0;
		if(a[i]>1) flagb=0;
	} 
	teshu();
	if(flag) return 0;
	ll l=1,r=n-1;
	return 0;
} 
