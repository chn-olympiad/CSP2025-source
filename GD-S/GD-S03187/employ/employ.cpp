#include<cstdio>
using namespace std;
const int MAXN=10;
int n,m;
char s[MAXN+10];
int a[MAXN+10];
int b[MAXN+10];
int ans=0;
bool vis[MAXN+10];
void dfs(int x){
	if(x>n){
		int cnt1=0;
		int cnt2=0;
		for(int i=1;i<=n;i++){
			if(cnt2>a[b[i]]){
				++cnt2;
			}else if(s[i]==0){
				++cnt2;
			}else{
				++cnt1;
			}
		}
		if(cnt1>=m){
			++ans;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			b[x]=i;
			dfs(x+1);
			vis[i]=false;
		}
	}
	return;
}
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
