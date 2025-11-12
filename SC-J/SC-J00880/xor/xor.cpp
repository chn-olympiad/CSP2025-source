#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll ans,f[N],n,k,arr[N];
unordered_map<ll,ll>pos;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;++i){
		cin >> arr[i];
		arr[i] ^= arr[i-1];
	}pos[0] = 0;
	for(int i = 1;i <= n;++i){
		f[i] = f[i-1];
		if(pos.count(arr[i]^k)) f[i] = max(f[i],f[pos[arr[i]^k]]+1);
		pos[arr[i]] = i;
	}cout << f[n] << "\n";
	return 0;
}