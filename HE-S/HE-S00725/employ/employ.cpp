#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,m,c[505],t,ans=0;
string s;
int vis[505],tot,had,cnt,qwq[505];
bool check(){
	had=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&had<c[qwq[i]])cnt++;
		else had++;
	}
	if(cnt>=m)return 1;
	else return 0;
}
void dfs(int num){
	if(num==n){
		if(check())ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		
		vis[i]=1;
		qwq[++tot]=i;
		dfs(num+1);
		vis[i]=0;
		tot--;
	}
}
int maxn;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0)t++;
		maxn=max(maxn,c[i]);
	}
	if(m==1&&maxn==n){
		for(int i=2;i<n;i++){
				ans=ans*i%N;
			}
			printf("%lld\n",ans);
			return 0;
	}
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')flag=1;
	}
	if(flag==0){
		if(t==0){
			ans=1;
			for(int i=2;i<=n;i++){
				ans=ans*i%N;
			}
			printf("%lld\n",ans);
		}else printf("0\n");
	}else{
		dfs(0);
		printf("%lld",ans);
	}
	return 0;
}
