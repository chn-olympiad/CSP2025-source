#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=505;
const ll mod=998244353;
ll ans=0;
int s[N],c[N];
char ch;
int vis[N],a[N];
void solve(){
	int sum=0,fanqi=0;
	for(int i=1;i<=n;i++){
	//	printf("%d ",c[a[i]]);
		if(s[i]==1&&c[a[i]]>fanqi){
			sum++;
		}else fanqi++;
	}
	//printf("sum:%d\n",sum);
	ans+=(sum>=m);
	return ;
}
void dfs(int now){
	if(now>n){
		solve();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		a[now]=i;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
	}
}
int main(){
	//ios::sync_stdio_with(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	cin>>ch;
    	if(ch=='1')s[i]=1;
    	else s[i]=0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1); 
	printf("%lld",ans);
	return 0;
}
