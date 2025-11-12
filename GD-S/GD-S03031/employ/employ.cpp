#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int p=998244353;
int n,m,c[N],vis[N],tmp[N],ans;
char s[N];
void dfs(int st){
	if(st>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1' && cnt<c[tmp[i]]) continue;
			else cnt++;
		}
		if(cnt<=n-m) ans=(ans+1)%p;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			tmp[st]=i;
			dfs(st+1);
			vis[i]=0;
		}
	}
}
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	//for(int i=1;i<=n;i++) cout<<s[i];
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}

