#include <bits/stdc++.h>
using namespace std;
int n,k,a[500009],maxn=-1;
void dfs(int st,int cnt){
	if(st>=n){
		maxn=max(maxn,cnt);
		return ;
	}
	int ans=-1;
	for(int i=st;i<=n;i++){
		if(ans==-1) ans=a[i];
		else ans^=a[i];
		if(ans==k){
			dfs(i+1,cnt+1);
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1) cnt1++;
	}
	if(cnt1==n){
		if(k==0){
			cout << cnt1/2;
			return 0;
		}
	}
	dfs(1,0);
	cout << maxn;
	return 0;
}
