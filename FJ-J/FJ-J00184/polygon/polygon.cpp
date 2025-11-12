#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long a[5010],pre[5010]={1},ans,cnt;
void dfs(int x,int k,int sum){
	for(int i=k+1;i<=n;i++){
		if(sum>a[i]&&x>2){
			ans++;
		}
		dfs(x+1,i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==1) cnt++;
	}
	if(cnt==n){
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]*i;
			pre[i]%=mod;
		}
		for(int i=3;i<=n;i++){
			ans+=(pre[n]/pre[n-i])/pre[i];
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
}
