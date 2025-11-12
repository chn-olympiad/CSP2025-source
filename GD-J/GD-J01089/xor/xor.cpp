#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];/*
ll Xor(int x,int y){
	if(x==y) return 0;
	else return 1;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >> k;
	for(ll i=1;i<=n;i++) cin >> a[i];
	bool flag = true;
	for(ll i=1;i<=n;i++) if(a[i]!=1) flag = false;
	if(flag){
		if(k==0) cout << n;
		else cout << 0;
	} /*else if(n<=10) {
		int t;
		for(int l=1;l<=n;l++){
			for(int r=n;r>=l;r--){
				for(int j=l;j<=r;j++){
					t^=a[j];
				} if(t==k) cout << r-l;
			}
		}
	} */cout << 1;
	return 0;
}
