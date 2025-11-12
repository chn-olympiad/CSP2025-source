#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[0]+=a[i];
	}
	for(int i=3;i<=a[0];i++){
		ll k=1;
		for(ll j=i+1;j<=a[0];j++){
			k*=j;
		}
		s+=k;
	}
	cout<<s;
	return 0;
} 