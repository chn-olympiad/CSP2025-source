#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
int n,a[N],ans;
bool vis[N],flag=1;
void dfs(int last,int sum,int maxn,int step){
	if(step>=4){
		if(sum>maxn*2)ans=(ans+1)%MOD;
		if(step>n)return;
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(i,sum+a[i],max(maxn,a[i]),step+1);
			vis[i]=0;
		}
	}
}
void spa(){
	long long x=1;
	for(int i=1;i<=n;i++){
		x=1LL*(x*2)%MOD;
	}
	x--;
	x-=n;
	long long y=n*(n-1)/2;
	x=1LL*((x+MOD)-y)%MOD;
	cout<<x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag==1){
		spa();
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
