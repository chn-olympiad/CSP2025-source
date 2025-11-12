#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5002;
const ll mod=998244353;
ll a[N];
ll pr[N];
ll n;
ll ma=-1;
bool cnt(ll i,ll j){
return i<j;}

int main()
{
//n-2 * n-1 /2
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
	}
	sort(a+1,a+n+1,cnt);
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
			return 0;
		}
		else 
		{
			cout<<0;
			return 0;
		}
	}
	
	cout<<1*(n)%mod*(n)-3%mod*(n)+1;
	return 0;
}
