#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n,m,k,sp,ans,bj;
int g[10010][10010],c[10010],gz[10010][10010],dp[10010][10010];//第 个乡镇，连接第 个村庄
int b[10010],tj[10010];
void p(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	
}
void f(int x,lld ans1){
	//cout<<x<<' '<<ans1<<" "<<ans<<'\n';//
	if(b[x]==1)return;
	b[x]=1;bj++;
	for(int i=1;i<=n;i++){
		if(b[i]==1)continue;
		if(x==i)continue;
		if(dp[x][i]==1e9)continue;
		f(i,ans1+dp[x][i]);
	}
	if(bj==n){
		ans=min(ans,ans1);
		//cout<<'!';cout<<x<<' '<<ans1<<" "<<ans<<'\n';//
	}
	b[x]=0;bj--;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e9;
			g[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&g[x][y]);
		g[y][x]=g[x][y];
		dp[x][y]=g[x][y],dp[y][x]=g[x][y];
		tj[x]++;tj[y]++;
		//if(tj[x]==1)bj++;
		//cout<<dp[x][y]<<'\n';
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)sp++;
		for(int j=1;j<=n;j++){
			scanf("%d",&gz[i][j]);
		}
	}//输入
	if(k==0){
		for(int i=1;i<=n;i++)f(i,0);
		printf("%lld",ans);
		return 0;
	}else if(sp==k){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int p=1;p<=k;p++){
					dp[i][j]=min(dp[i][j],gz[p][i]+gz[p][j]);
					//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
				}
			}
		}
		for(int i=1;i<=n;i++)f(i,0);
		printf("%lld",ans);
		return 0;
	}
	
	//cout<<'#';
	ans=1e9;
	//p();
	for(int i=1;i<=n;i++)f(i,0);
	//printf("%lld ",ans);cout<<'^'<<ans;//
	lld ans2=ans;
	ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int p=1;p<=k;p++){
				dp[i][j]=min(dp[i][j],gz[p][i]+gz[p][j]+c[p]);
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
				//cout<<'!';cout<<i<<' '<<j<<' '<<p<<'\n';
			}
		}
	}
	//cout<<'!';
	//p();
	for(int i=1;i<=n;i++)f(i,0);
	ans=min(ans2,ans);
	printf("%lld ",ans);
	return 0;
}