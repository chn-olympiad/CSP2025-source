#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int num[10010],n;
bool vis[10010];
void dfs(int min_num,int chang,int maxn,int js){
	if(js>=3){
		if(chang>maxn*2)ans++;
		ans%=998244353;
	}
	for(int i=min_num;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(i,chang+num[i],max(maxn,num[i]),js+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
