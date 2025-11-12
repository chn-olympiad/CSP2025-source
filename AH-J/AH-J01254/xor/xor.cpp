#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],f[N];
map<int,int> mp;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if((mp[b[i]^k]!=0)||((b[i]^k)==0))
			f[i]=max(f[i],f[mp[b[i]^k]]+1);
		mp[b[i]]=i;
	}
	cout<<f[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int QwQawaqaq=1;
	while(QwQawaqaq--)
		solve();
	return 0;
}
//申请上迷惑行为大赏QwQ
