#include<bits/stdc++.h> 
using namespace std;
int t,n,cnt,ans;
struct O{
	int a,b,c;
}p[100005];
int dp[100005][4][4];
int d[25];
int e[4];
void check(){
	cnt=0;
	for(int i=1;i<=n;i++){
		if(d[i]==1) cnt+=p[i].a;
		if(d[i]==2) cnt+=p[i].b;
		if(d[i]==3) cnt+=p[i].c;
	}
	ans=max(ans,cnt);
}
void dfs(int x){
	for(int i=1;i<=3;i++){
		if(e[i]==n/2) continue;
		d[x]=i;
		e[i]++;
		if(x==n) check();
		if(x<n) dfs(x+1);
		e[i]--;
	}
	return;
}
void df(){
	ans=0;
	memset(e,0,sizeof(e));
	dfs(1);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		}
		if(n<=20){
			df();
			continue;
		}
		for(int i=1;i<=n;i++){
			int d=max(dp[i-1][1][0],dp[i-1][2][0]);
			d=max(d,dp[i-1][3][0]);
			if(d==dp[i-1][1][0]){
				if(dp[i-1][1][1]==n/2){
					if(dp[i-1][2][0]>=dp[i-1][3][0]){
						dp[i][1][0]=dp[i-1][2][0]+p[i].a;
						dp[i][1][1]=dp[i-1][2][1]+1;
						dp[i][1][2]=dp[i-1][2][2];
						dp[i][1][3]=dp[i-1][2][3];
					}else{
						dp[i][1][0]=dp[i-1][3][0]+p[i].a;
						dp[i][1][1]=dp[i-1][3][1]+1;
						dp[i][1][2]=dp[i-1][3][2];
						dp[i][1][3]=dp[i-1][3][3];
					}	
				}else{
					dp[i][1][0]=dp[i-1][1][0]+p[i].a;
					dp[i][1][1]=dp[i-1][1][1]+1;
					dp[i][1][2]=dp[i-1][1][2];
					dp[i][1][3]=dp[i-1][1][3];
				}
				if(dp[i-1][1][2]==n/2){
					if(dp[i-1][2][0]>=dp[i-1][3][0]){
						dp[i][2][0]=dp[i-1][2][0]+p[i].b;
						dp[i][2][1]=dp[i-1][2][1];
						dp[i][2][2]=dp[i-1][2][2]+1;
						dp[i][2][3]=dp[i-1][2][3];
					}else{
						dp[i][2][0]=dp[i-1][3][0]+p[i].b;
						dp[i][2][1]=dp[i-1][3][1];
						dp[i][2][2]=dp[i-1][3][2]+1;
						dp[i][2][3]=dp[i-1][3][3];
					}	
				}else{
					dp[i][2][0]=dp[i-1][1][0]+p[i].b;
					dp[i][2][1]=dp[i-1][1][1];
					dp[i][2][2]=dp[i-1][1][2]+1;
					dp[i][2][3]=dp[i-1][1][3];
				}
				if(dp[i-1][1][3]==n/2){
					if(dp[i-1][3][0]>=dp[i-1][2][0]){
						dp[i][3][0]=dp[i-1][3][0]+p[i].c;
						dp[i][3][1]=dp[i-1][3][1];
						dp[i][3][2]=dp[i-1][3][2];
						dp[i][3][3]=dp[i-1][3][3]+1;
					}else{
						dp[i][3][0]=dp[i-1][2][0]+p[i].c;
						dp[i][3][1]=dp[i-1][2][1];
						dp[i][3][2]=dp[i-1][2][2];
						dp[i][3][3]=dp[i-1][2][3]+1;
					}	
				}else{
					dp[i][3][0]=dp[i-1][1][0]+p[i].c;
					dp[i][3][1]=dp[i-1][1][1];
					dp[i][3][2]=dp[i-1][1][2];
					dp[i][3][3]=dp[i-1][1][3]+1;
				}
			}
			if(d==dp[i-1][2][0]){
				if(dp[i-1][2][1]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][3][0]){
						dp[i][1][0]=dp[i-1][1][0]+p[i].a;
						dp[i][1][1]=dp[i-1][1][1]+1;
						dp[i][1][2]=dp[i-1][1][2];
						dp[i][1][3]=dp[i-1][1][3];
					}else{
						dp[i][1][0]=dp[i-1][3][0]+p[i].a;
						dp[i][1][1]=dp[i-1][3][1]+1;
						dp[i][1][2]=dp[i-1][3][2];
						dp[i][1][3]=dp[i-1][3][3];
					}	
				}else{
					dp[i][1][0]=dp[i-1][2][0]+p[i].a;
					dp[i][1][1]=dp[i-1][2][1]+1;
					dp[i][1][2]=dp[i-1][2][2];
					dp[i][1][3]=dp[i-1][2][3];
				}
				if(dp[i-1][2][2]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][3][0]){
						dp[i][2][0]=dp[i-1][1][0]+p[i].b;
						dp[i][2][1]=dp[i-1][1][1];
						dp[i][2][2]=dp[i-1][1][2]+1;
						dp[i][2][3]=dp[i-1][1][3];
					}else{
						dp[i][2][0]=dp[i-1][3][0]+p[i].b;
						dp[i][2][1]=dp[i-1][3][1];
						dp[i][2][2]=dp[i-1][3][2]+1;
						dp[i][2][3]=dp[i-1][3][3];
					}	
				}else{
					dp[i][2][0]=dp[i-1][2][0]+p[i].b;
					dp[i][2][1]=dp[i-1][2][1];
					dp[i][2][2]=dp[i-1][2][2]+1;
					dp[i][2][3]=dp[i-1][2][3];
				}
				if(dp[i-1][2][3]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][3][0]){
						dp[i][3][0]=dp[i-1][1][0]+p[i].c;
						dp[i][3][1]=dp[i-1][1][1];
						dp[i][3][2]=dp[i-1][1][2];
						dp[i][3][3]=dp[i-1][1][3]+1;
					}else{
						dp[i][3][0]=dp[i-1][3][0]+p[i].c;
						dp[i][3][1]=dp[i-1][3][1];
						dp[i][3][2]=dp[i-1][3][2];
						dp[i][3][3]=dp[i-1][3][3]+1;
					}	
				}else{
					dp[i][3][0]=dp[i-1][2][0]+p[i].c;
					dp[i][3][1]=dp[i-1][2][1];
					dp[i][3][2]=dp[i-1][2][2];
					dp[i][3][3]=dp[i-1][2][3]+1;
				}
			}
			if(d==dp[i-1][3][0]){
				if(dp[i-1][3][1]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][2][0]){
						dp[i][1][0]=dp[i-1][1][0]+p[i].a;
						dp[i][1][1]=dp[i-1][1][1]+1;
						dp[i][1][2]=dp[i-1][1][2];
						dp[i][1][3]=dp[i-1][1][3];
					}else{
						dp[i][1][0]=dp[i-1][2][0]+p[i].a;
						dp[i][1][1]=dp[i-1][2][1]+1;
						dp[i][1][2]=dp[i-1][2][2];
						dp[i][1][3]=dp[i-1][2][3];
					}	
				}else{
					dp[i][1][0]=dp[i-1][3][0]+p[i].a;
					dp[i][1][1]=dp[i-1][3][1]+1;
					dp[i][1][2]=dp[i-1][3][2];
					dp[i][1][3]=dp[i-1][3][3];
				}
				if(dp[i-1][3][2]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][2][0]){
						dp[i][2][0]=dp[i-1][1][0]+p[i].b;
						dp[i][2][1]=dp[i-1][1][1];
						dp[i][2][2]=dp[i-1][1][2]+1;
						dp[i][2][3]=dp[i-1][1][3];
					}else{
						dp[i][2][0]=dp[i-1][2][0]+p[i].b;
						dp[i][2][1]=dp[i-1][2][1];
						dp[i][2][2]=dp[i-1][2][2]+1;
						dp[i][2][3]=dp[i-1][2][3];
					}	
				}else{
					dp[i][2][0]=dp[i-1][3][0]+p[i].b;
					dp[i][2][1]=dp[i-1][3][1];
					dp[i][2][2]=dp[i-1][3][2]+1;
					dp[i][2][3]=dp[i-1][3][3];
				}
				if(dp[i-1][3][3]==n/2){
					if(dp[i-1][1][0]>=dp[i-1][2][0]){
						dp[i][3][0]=dp[i-1][1][0]+p[i].c;
						dp[i][3][1]=dp[i-1][1][1];
						dp[i][3][2]=dp[i-1][1][2];
						dp[i][3][3]=dp[i-1][1][3]+1;
					}else{
						dp[i][3][0]=dp[i-1][2][0]+p[i].c;
						dp[i][3][1]=dp[i-1][2][1];
						dp[i][3][2]=dp[i-1][2][2];
						dp[i][3][3]=dp[i-1][2][3]+1;
					}	
				}else{
					dp[i][3][0]=dp[i-1][3][0]+p[i].c;
					dp[i][3][1]=dp[i-1][3][1];
					dp[i][3][2]=dp[i-1][3][2];
					dp[i][3][3]=dp[i-1][3][3]+1;
				}
			}
		}
		int f=max(dp[n][1][0],dp[n][2][0]);
		f=max(f,dp[n][3][0]);
		printf("%d\n",f);
	}
	return 0;
}
