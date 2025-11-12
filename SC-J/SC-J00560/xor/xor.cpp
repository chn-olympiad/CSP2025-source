#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
#define ll long long

ll n,m,k,ans;
ll a[N],b[N];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	ll lass=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			lass=i;
			ans++;
			continue;
		}
		for(int j=i-1;j>lass;j--){
			ll xorr=b[i];
			xorr^=b[j-1];
			if(xorr==k){
				lass=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	
	return 0;
}