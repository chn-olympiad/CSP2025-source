#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=(1<<20)+10;
ll n,a[N]={},k,b[M]={},f[N]={};
void solve(){
	memset(b,-1,sizeof(b));
	b[0]=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		ll p=a[i]^k;
		f[i]=f[i-1];
		if(b[p]!=-1)
			f[i]=max(f[i],f[b[p]]+1);
		b[a[i]]=i;
	}
	cout<<f[n];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}
