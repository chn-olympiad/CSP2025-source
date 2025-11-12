#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5005],b[5005];
int n,ans;

void dfs(int m,int l,int x){
	if(m>=3&&l>2*a[x]){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		dfs(m+1,l+a[i],i);
		b[i]=0;
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return ;
	}
	dfs(0,0,0);
	cout<<ans%998244353;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
}//awa
