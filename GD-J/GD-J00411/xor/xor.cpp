#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],n,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[i]^a[j]==k)ans++;
		}
	}
	cout<<ans;
	
	
	return 0;
}
