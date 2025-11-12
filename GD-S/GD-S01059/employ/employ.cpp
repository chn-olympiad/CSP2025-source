#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=510;
const int MOD=998244353;
int n,m,ans,c[N],rd[N];
bool vis[N];
string s;
bool check(){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(i-1-tot<c[rd[i]]&&s[i-1]=='1') tot++;
	}
	return tot>=m;
} 
void dfs(int k){
	if(k==n+1){
//		for(int i=1;i<=n;i++){
//			printf("%d ",rd[i]);
//		}
//		printf("\n");
		if(check()){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			rd[k]=i;
			vis[i]=true;
			dfs(k+1);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans%MOD);
	return 0;
}
