#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	ll n1=n;
	vector<ll> a(n+1);
	vector<ll> u(n+1);
	vector<ll> v(n+1);
	vector<ll> w(n+1);
	vector<ll> w1(n+1);
	for(ll i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		a[i]=1;
	} 
	sort(w.begin(),w.end());
	ll sum=0;
	for(ll i=1;i<=n-1;i++){
		sum+=w[i];
	}
	cout<<sum<<endl;
	return 0;
}

