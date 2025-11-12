#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],mod=998244353,ans=1,cnt,num[20],vis[20];
char s[505];
void dfs(int dep){
	if(dep==n+1){
		cnt=0;
		for(int i=1;i<=n;i++) if(s[i]=='0'||cnt>=a[num[i]]) cnt++;
		if(n-cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		num[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		ans=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		dfs(1);
		cout<<ans;
	}else{
		cin>>s;
		cnt=n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==0) cnt--;
		}
		if(cnt<m){
			printf("0");
			return 0;
		}
		for(long long i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld",ans);
	}
	return 0;
}
