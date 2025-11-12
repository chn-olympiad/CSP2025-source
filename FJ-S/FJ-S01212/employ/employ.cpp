#include <cstdio>
#include <cstring>
int n,m,ans,c[100005],a[100005];
char s[100005];
bool mark[100005];
bool check(){
	int cnt = 0,wuren = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '1' && wuren < c[a[i]]){
			cnt ++;
		}
		else{
			wuren ++;
		}
	}
	return cnt >= m;
}
void dfs(int p){
	if(p > n){
		if(check()) ans ++;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!mark[i]){
			mark[i] = true;
			a[p] = i;
			dfs(p+1);
			mark[i] = false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

