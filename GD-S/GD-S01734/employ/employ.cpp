#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N];
ll ans;
char s[N];
bool bz[N];

void dfs(int x,int y){
	if(n-x+1+y<m) return;
	if(x>n){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bz[i]) continue;
		bz[i]=1;
		dfs(x+1,y+((s[x]=='1'&&c[i]>x-1-y)?1:0));
		bz[i]=0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=11){
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
