#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e3+5;//5e3+5
int n,a[N],m,b[N],fg,ans=0;
bool vis[N]={false};
bool check(int k){
	int r=0;
	for(int i=1;i<k;i++)
		r+=b[i];
	return r>2*b[k-1];
}

void dfs(int k,int l){
	if(k==m+1){
		if(check(k))
			ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=true&&l<i){
			vis[i]=true;
			b[k]=a[i];
			dfs(k+1,i);
			vis[i]=false;
		}
	}
}

signed main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		m=i;
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}
