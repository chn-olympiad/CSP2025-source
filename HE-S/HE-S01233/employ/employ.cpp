#include <cstdio>
#include <cstring>

const int mod=998244353;
int n,m;
char s[505];
bool diff[505];
int c[505];
int order[505];
bool vis[505];
int res;
void dfs(int depth){
	if(depth>n){
		int failed=0;
		int ac=0;
		for(int i=1;i<=n;i++){
			if(!diff[i] || failed>=c[order[i]])
				failed++;
			else	ac++;
		}
		res+=(ac>=m);
		res%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		order[depth]=i;
		dfs(depth+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	int len=strlen(s);
	bool tA=1;
	for(int i=0;i<len;i++){
		diff[i+1]=s[i]-'0';
		if(!diff[i+1])	tA=0;
	}
	for(int i=1;i<=n;i++)	scanf("%d",&c[i]);
	dfs(1);
	printf("%d",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
