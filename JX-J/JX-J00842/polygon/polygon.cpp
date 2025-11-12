#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5005],ans;
void dfs(int cnt,int num,int maxn,int cnt2){
	if(cnt2>n)return;
	if(cnt>=3&&num>2*maxn){
		ans=(ans+1)%mod;
	}
	if(cnt==1)for(int i=cnt2+1;i<=n-1;i++)dfs(cnt+1,num+a[i],max(maxn,a[i]),i);
	else for(int i=cnt2+1;i<=n;i++)dfs(cnt+1,num+a[i],max(maxn,a[i]),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(1,a[i],a[i],i);
	}
	cout<<ans;
	return 0;
}
