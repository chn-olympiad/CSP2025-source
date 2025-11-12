#include<bits/stdc++.h>
using namespace std;
struct club{
	int a1,a2,a3;
};
club e[100005];
int n,T;
int vis[4];
long long dp[100005][4];
long long maxm(long long a,long long b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=3;j++) dp[i][j]=-1e+6;
		  for(int i=1;i<=3;i++) vis[i]=n/2-1;
		  //memset(vis,0,sizeof(vis));
	    for(int i=1;i<=n;i++){
	    cin>>e[i].a1>>e[i].a2>>e[i].a3;
//	    e[i].maxx=max(max(e[i].a1,e[i].a2),e[i].a3);
//	    e[i].minn=min(min(e[i].a1,e[i].a2),e[i].a3);
//	    e[i].mid=e[i].a1+e[i].a2+e[i].a3-e[i].maxx-e[i].minn;
//	    if(e[i].maxx==e[i].a1) e[i].maxxb=1;
//	    if(e[i].maxx==e[i].a2) e[i].maxxb=2;
//	    if(e[i].maxx==e[i].a3) e[i].maxxb=3;
//	    if(e[i].mid==e[i].a1) e[i].midxb=1;
//	    if(e[i].mid==e[i].a2) e[i].midxb=2;
//	    if(e[i].mid==e[i].a3) e[i].midxb=3;
//	    if(e[i].minn==e[i].a1) e[i].minnxb=1;
//	    if(e[i].minn==e[i].a2) e[i].minnxb=2;
//	    if(e[i].minn==e[i].a3) e[i].minnxb=3;
	    }
	    //sort(e+1,e+n+1,cmp);
	    if(n==2){
	    	int maxn=max(e[1].a1+e[2].a2,e[1].a1+e[2].a3);
	    	maxn=max(e[1].a2+e[2].a1,max(e[1].a2+e[2].a3,maxn));
	    	maxn=max(e[1].a3+e[2].a1,max(e[1].a3+e[2].a2,maxn));
	    	cout<<maxn<<endl;
	    	continue;
		}
	    dp[n][1]=e[n].a1;dp[n][2]=e[n].a2;dp[n][3]=e[n].a3;
	    //cout<<dp[1][1]<<' '<<dp[1][2]<<' '<<dp[1][3]<<endl;
	    for(int i=n;i>=1;i--){
	    	if(vis[1]>=1) {
	    		dp[i][1]=maxm(maxm(dp[i][1],dp[i+1][1]+e[i].a1),maxm(dp[i+1][2]+e[i].a1,dp[i+1][3]+e[i].a1));
	    		vis[1]--;
			}
			if(vis[2]>=1) {
	    		dp[i][2]=maxm(maxm(dp[i][2],dp[i+1][1]+e[i].a2),maxm(dp[i+1][2]+e[i].a2,dp[i+1][3]+e[i].a2));
	    		vis[2]--;
			}
			if(vis[3]>=1) {
	    		dp[i][3]=maxm(maxm(dp[i][3],dp[i+1][1]+e[i].a3),maxm(dp[i+1][2]+e[i].a3,dp[i+1][3]+e[i].a3));
	    		vis[3]--;
			}
			long long maxn=maxm(maxm(dp[i][1],dp[i][2]),dp[i][3]);
			if(maxn==dp[i][1]){vis[2]++;vis[3]++;}
			if(maxn==dp[i][2]){vis[1]++;vis[3]++;}
			if(maxn==dp[i][3]){vis[2]++;vis[1]++;}
			//cout<<i<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
		}
		ans=maxm(dp[1][1],maxm(dp[1][2],dp[1][3]));
		cout<<ans<<endl;
    }
	fclose(stdin);fclose(stdout);
	return 0;
}
