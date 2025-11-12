#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5007];
int ans;
int n;
int N=998244353;
void dfs(int sum,int x){
	for(int i=x+1;i<=n;i++){
		if(sum>a[i]){
			ans++;
			ans%=N;
		}	
		dfs(sum+a[i],i);
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
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	return 0;
}
