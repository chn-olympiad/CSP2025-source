#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int MAXN=250;
ll n,m,x,a[MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m*n-1;j++){
			if(a[j+1]<a[j]) swap(a[j+1],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(i%m==0) cout<<m;
			else cout<<i%m;
			cout<<" ";
			if((i-1)/n==0) cout<<1;
			else cout<<i/n+1;
			return 0;
		}
	}
	return 0;
} 
