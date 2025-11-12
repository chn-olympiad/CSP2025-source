#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int n,k;
int a[500005];
int d[500005];
map<pii,bool> mp;
int cnt;
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=d[i-1]^a[i];
	}
	mp[{k,0}]=1;
	for(int i=1;i<=n;i++){
		//cout<<d[i]<<" ";
		if(mp[{d[i],cnt}]==1){
			ans++;
			cnt++;
		}
		mp[{k^d[i],cnt}]=1;
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
