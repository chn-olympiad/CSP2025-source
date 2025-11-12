#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[505],ans;
void dfs(int cnt,int sum,int da,int l){
	if(cnt==0){
//		cout<<sum<<" "<<da<<"\n";
		if(sum>da*2){
			ans++;
		}
		return;
	}
	for(int i=l+1;i<=n;i++){
		dfs(cnt-1,sum+a[i],max(da,a[i]),i);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0);
	}
	cout<<ans;
	return 0;
}
