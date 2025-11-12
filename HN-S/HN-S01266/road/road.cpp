#include <bits/stdc++.h> 
using namespace std;
long long n,m,k,sum=0,pop1[110000];
struct st{
	long long v[1100];
	long long w[1100],len;
}dp[1100];
void bfs(int sc,int qd){
	while(1){
		long long zux=dp[qd].w[1],zuy=1;	
		for(int i=2;i<=dp[qd].len;i++){
			if(zux!=min(zux,dp[qd].w[i])){
				zux=min(zux,dp[qd].w[i]);
				zuy=i;
			}
		} 
		if(dp[qd].v[zuy]!=sc){
			sum+=zux;
			bfs(qd,dp[qd].v[zuy]);
			return ;
		}else{
			dp[qd].w[zuy]=100000000;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int j=1;j<=m;j++){
		int q,g,z;
		cin>>q>>g>>z;
		dp[q].len++;
		dp[g].len++;
		dp[q].v[dp[q].len]=g;
		dp[g].v[dp[g].len]=q;
		dp[q].w[dp[q].len]=z;
		dp[g].w[dp[g].len]=z;
	}
	for(int i=1;i<=k;i++){
		int cum;
		cin>>cum;
		for(int j=1;j<=n;j++) cin>>pop1[j];
		for(int j=1;j<=n;j++){
			for(int op=1;op<=n;op++){
				dp[j].w[dp[j].len]=min(dp[j].w[dp[j].len],cum+pop1[op]+pop1[j]);
				dp[j].v[dp[j].len]=op;
				dp[op].v[dp[op].len]=j;
				dp[op].w[dp[op].len]=min(dp[op].w[dp[op].len],cum+pop1[op]+pop1[j]);
			}
		}
	}
	bfs(0,1);
	cout<<sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
