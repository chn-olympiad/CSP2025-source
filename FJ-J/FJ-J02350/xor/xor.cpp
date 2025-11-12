#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e6+100;
int n,k,a[N],ans=0,b[N];
bool vis[N];
signed main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=i;j>=1;j--){
			if(vis[j]) break;
			if((b[i]^b[j-1])==k){
//				cout<<j<<' '<<i<<endl;
				ans++,vis[i]=1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
