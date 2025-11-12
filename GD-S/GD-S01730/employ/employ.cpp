#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110,mod=998244353;
int n,a[N],s[N],m,ans,p[N],vis[N];
string t; 
void dfs(int x){
	if(x==(n+1)){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=a[p[i]]||!s[i]){
				sum++;
			}
		}
		if(sum<=(n-m)){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	} 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>t;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=t[i-1]-'0';
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
