#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
map<int,bool> mp;
int a[N];
int c[N];
int n,k,ans;
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	c[0]=-1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(c[i-1]==-1)c[i]=a[i];
		else c[i] = c[i-1] ^ a[i];
		if(mp[c[i]^k]||c[i]==k){
			++ans;
			//~ cout << "debug:"<< i << '\n';
			mp.clear();
			c[i]=-1;
			continue;
		}
		mp[c[i]]=true;
		//~ cout << c[i] << '\n';
	}
	cout<<ans;
}
