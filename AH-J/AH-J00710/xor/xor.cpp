#include<bits/stdc++.h>
#define int long long
using namespace std;
int xo[500005],a[500005];
int n,k,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
	}
	int l=1;
	map<int,int> mp;
	mp[0]=1;
	for(int r=1;r<=n;r++){
		int xoo;
		if(l==r){
			xoo=a[l];
		}else{
			xoo=xoo^a[r];
		}
//		cout<<xoo<<" "<<(xoo^k)<<"\n";
		if(mp[xoo^k]){
//			cout<<"\n";
			ans++;
			l=r+1;
			mp.clear();
			mp[0]=1;
		}else{
			mp[xoo]++;
		}
	}
	cout<<ans;
	return 0;
}
