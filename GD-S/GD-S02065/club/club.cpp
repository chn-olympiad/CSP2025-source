#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n;
long long value[100010][4];//第一个是人的编号，第二个是部门 
//有n个组，每组选一个，每种类型的限选n/2种 
int group_[4];
long long ans=-1;
void dfs(int x,long long tmp){
	if(x==n+1){
		ans=max(ans,tmp);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(group_[i]>=(n/2)){
			continue;
		}else{
			group_[i]++;
			tmp+=value[x][i];
			dfs(x+1,tmp);
			tmp-=value[x][i];
			group_[i]--;
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		memset(group_,0,sizeof(group_));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&value[i][j]);
			}
		} 
		dfs(1,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
