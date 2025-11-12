#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=505;
const ll mod=998244353;
int n,m;
int S[N],scnt,C[N];
ll ans;

bool flag=1;
void ggetin(){
	char c=getchar();
	while(c<'0'||c>'1'){
		c=getchar();
	}
	while(c>='0'&&c<='1'){
		S[++scnt]=c-'0';
		if(S[scnt]==0) flag=0;
		c=getchar();
	}
}
int now[N];
bool vis[N]; 
bool check(){
	
	int num=0,ref=0;
	for(int i=1;i<=n;i++){
		if(S[i]==1){
			if(C[now[i]]>ref)num++;
			else ref++;
		}
		if(S[i]==0) ref++;
	}
	
	if(num>=m) return 1;
	return 0;
}

void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
			ans%=mod; 
		}
		return; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		now[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	ggetin();
	for(int i=1;i<=n;i++){
		scanf("%d",&C[i]);
	}
	if(flag){
		ans=1;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(C[i]==0) tmp++;
		}
		for(int i=n;i>=n-tmp+1;i--){
			ans*=i;
			ans%=mod;
		}
	}
	else{
		dfs(1);
	}
	printf("%lld\n",ans);
	return 0;
} 
