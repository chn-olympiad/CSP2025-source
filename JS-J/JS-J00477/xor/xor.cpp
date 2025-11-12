#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll n,k,a[N],b[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=0;
			continue;
		}
		b[i]=b[i-1]^a[i];
		if(b[i]==k){
			ans++;
			b[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
