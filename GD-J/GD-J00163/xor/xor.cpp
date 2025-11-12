#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;

int n,k,a[N],sum[N],f[N];
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	mp[0]=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
		f[i]=f[i-1];
		if (mp.count(sum[i]^k)){
			f[i]=max(f[i],f[mp[sum[i]^k]]+1);
		}
		mp[sum[i]]=i;
	}
	cout << f[n];
} 
