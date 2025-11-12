#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,a[5005];
long long ans;
void dfs(int now,int sum,int maxn){
	if(now>n){
		if((sum>0)&&(sum>2*maxn)){
			ans++;
			ans%=P;
		}
		return;
	}
	dfs(now+1,sum+a[now+1],max(maxn,a[now+1]));
	dfs(now+1,sum,maxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans%P/2;
	return 0;
}
