#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k,a[N];
map<int,int> mp;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	mp[0]=1;
	int xo=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo^=a[i];
		if(mp[xo^k]){
			cnt++;
			mp.clear();
		}
		mp[xo]++;
	}
	cout<<cnt;
	return 0;
}