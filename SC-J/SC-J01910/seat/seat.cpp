#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000],jl,ans;
void out(ll hs,ll ls){
	cout<<hs<<' ';
	if(hs%2==0)
		cout<<n-ls+1;
	else cout<<ls;
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	jl=a[1];
	sort(a+1,a+n*m+1,greater<ll>());
	for(ll i=1;i<=n*m;i++)
		if(a[i]==jl){
			ans=i;
			break;
		}
	ll hs=(ans/n)+(ans%n==0?0:1);
	ll ls=ans-(hs-1)*n;
	out(hs,ls);
	return 0;
}