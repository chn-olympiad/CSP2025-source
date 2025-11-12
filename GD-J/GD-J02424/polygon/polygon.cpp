//polygon.cpp
#include<stdio.h>
#include<algorithm>
#include<string.h>
int n,a[(int)1e4*5+5],cnt,plan[100];
const int mod=998244353;
//bool vis[(int)1e5*5+1][(int)1e5*5+1];
void dfs(int now,int sum,int maxx){
	//printf("now%d,sum%d,maxx%d\n",now,sum,maxx);
	if(maxx*2<sum and maxx!=(int)-1e9){
		//puts("dddmm");
		//for(int i=1;plan[i]!=0;i++)printf("%d ",plan[i]);
		//puts("");
		cnt++%mod;
		//return ;
	}
	for(int i=1+now;i<=n;i++){
		///printf("i,%d\n",i);
		//plan[i]=a[i];
		dfs(i,sum+a[i],std::max(a[i],maxx));
	}
}
int main(){
	//memset(plan,0,sizeof(plan));
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//dfs(1,0,(int)-1e9);
	for(int i=1;i<=n;i++)dfs(i,a[i],(int)-1e9);
	printf("%d",cnt);
	return 0;
}

