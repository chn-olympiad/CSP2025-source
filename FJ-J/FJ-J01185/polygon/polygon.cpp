#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int mx=-1;
int r[N];
bool b[N];
set<int>st;
int a[N];
int n;
int ans;
void dfs(int now,int sum,int maxn,int id) {
	if(now>n+1)return;
	if(now>=3&&sum>maxn*2){
		//for(int i=1;i<now;i++)cout<<a[i]<<" ";
		//cout<<endl;
		ans++;
	}
	for(int i=id;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		a[now]=r[i];
		dfs(now+1,sum+r[i],max(maxn,r[i]),i);
		a[now]=0;
		b[i]=0;
	}
}
int jc(int x){
	if(x==0)return 1;
	int sum=1;
	for(int i=1;i<=x;i++)sum=(sum*i+MOD)%MOD;
	return sum;
}
int Ce(int n,int m){
	return ((jc(n)/(jc(m)*jc(n-m)))+MOD)%MOD;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>r[i];
		mx=max(mx,r[i]);
	}
	//cout<<jc(1);
	if(mx==1){
		int sum=0; 
		for(int i=3;i<=n;i++) {
			//cout<<jc(2)<<" ";
			sum=(sum+Ce(n,i)+MOD)%MOD;
		}
		cout<<sum;
		return 0;
	}
	sort(r+1,r+n+1);
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
}
/*
6
1 1 1 1 1 1
*/

