#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5005],n;
long long ans;
void dfs(int x,int cnt,long long sum,int maxn){
	if(cnt>=3&&sum>maxn*2){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,cnt+1,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		cout<<n-2;
		return 0;
	}
	dfs(1,0,0,-0x3f3f3f3f);
	dfs(1,1,a[1],a[1]);
	cout<<ans;
	return 0;
}
