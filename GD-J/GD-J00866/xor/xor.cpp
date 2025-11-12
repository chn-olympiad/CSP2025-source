#include<bits/stdc++.h>
using namespace std;
int sz[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int i, n, k, ans=0, l, r, x=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>sz[i];
	}
	l=0;
	r=1;
	x=sz[0];
	while(r<n){
		if(x==k){
			x=0;
			l=r-1;
			ans++;
		}
		x=x^sz[r];
		r++;
	}
	if(x==k){
		ans++;
	}
	cout<<ans;
	return 0;
}
