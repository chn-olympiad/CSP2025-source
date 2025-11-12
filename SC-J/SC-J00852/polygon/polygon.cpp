#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,a[5005],ans;
void dfs(int sum,int maxn,int k){
	if(sum>maxn*2 && sum!=0 && maxn!=0){
		ans++;
	}
	for(int i=k+1;i<=n;i++){
		dfs(sum+a[i],max(maxn,a[i]),i);
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){
		cout<<(n-1)*(n-2)/2;
	}else{
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
}