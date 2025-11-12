#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+9;
int n,k,a[N],r=1,ans;
map<int,int> mp={{0,1}};

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=2;i<=n+1;i++) cin>>a[i];
	for(int i=2;i<=n+1;i++) a[i]=a[i]^a[i-1];
	for(int i=2;i<=n+1;i++){
		if(mp[a[i]^k]>=r){
			r=i;
			ans++;
		}
		mp[a[i]]=i;
	}
	cout<<ans;
	return 0;
}
