/*
	
 4 2
 2 1 0 3
 
 4 0
 2 1 0 3
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[500100];
ll po(int l,int r)
{
	if(l==r)
	{
		ll ans=a[l]^a[r];
		return ans;	
	}
	ll ans=a[l];
	for(int i=l+1;i<=r;i++)
		ans=ans^a[i];
	return ans;
}
int selvo(ll k,ll n)
{
	int maxa=0;
	for(int l=1;l<=n;l++)
		for(int r=1;r<=n;r++)
			if(po(l,r)==k)
				maxa=max(maxa,r-l);	
	return maxa;
}
ll k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<selvo(k,n);
	return 0;
} 

