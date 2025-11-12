#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
const int MOD=998244353;
int a[N];
int n;
int ans=0;
void dfs(int sum,int i,int d,int MAX){
	if(d>=3&&sum>MAX*2){
		ans++;
		ans=ans%MOD;
	}
	int tMAX=MAX;
	for(;i<=n;i++){
		MAX=max(MAX,a[i]);
		sum+=a[i];
		dfs(sum,i+1,d+1,MAX);
		MAX=tMAX;
		sum-=a[i];
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
