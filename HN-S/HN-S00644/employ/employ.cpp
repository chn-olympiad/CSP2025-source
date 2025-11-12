#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int n,m,k;
struct node{
	int u,to,next;
	int w;
};
node e[2000005];
int cnt=0;
int head[10005];
int c[11];
int a[11][10005];
int sum[10005];
struct node1{
	int a;
	int b;
	int c;
};

node1 sz[1000005];
bool bsz[1000005];
bool cmp(node1 x,node1 y){
	return x.c<y.c;
}
int dp[10005][(1<<10)+1];
void add(int u,int v,int w){
	cnt++;
	e[cnt].next=head[u];
	e[cnt].u=u;
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
	return;
}
bool check(int x,int y){
	int re=(y>>(x-1))%2;
	return re;
}//第x位 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	int ccnt=0;
	for(int i=1;i<=m;i++){
		ccnt++;
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		
		sz[ccnt].a=u;
		sz[ccnt].b=v;
		sz[ccnt].c=w;
	}
	sort(sz+1,sz+1+ccnt,cmp);
	//cout<<ccnt<<endl;
	for(int i=1;i<=ccnt;i++){
		//cout<<sz[i].c<<endl;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=((1<<k)-1);j++){
			dp[i][j]=maxn;
		}
	}
	for(int i=0;i<=(1<<k)-1;i++){
		dp[0][i]=0;
		for(int j=1;j<=k;j++){
			if(check(j,i)==1){
				dp[0][i]+=c[j];
			}
		}
	}
	//cout<<check(2,3)<<endl;
	//cout<<dp[1][0]<<endl;
	
	//总共n-1条边	
			
	for(int ii=0;ii<=((1<<k)-1);ii++){
		int ncnt=1;
		for(int i=1;i<=n;i++){
			sum[i]=0;
		}
		int bo=0;
		for(int i=1;i<=n;i++){
			int minn=maxn;
			int minn1=maxn;
			
			while(1){
				if(sum[sz[ncnt].a]<=(2-bo)&&sum[sz[ncnt].b]<=(2-bo)){
					break;
				} 
				ncnt++;
			} 
			minn=sz[ncnt].c;
			int mp;
			int mq;
			//cout<<i<<" "<<ii<<" "<<minn<<endl;
			for(int j=1;j<=k;j++){
				if(check(j,ii)==1){
					for(int ij=1;ij<=n;ij++){
						if(j==ij&&minn1<a[j][ij]&&sum[j]<=(2-bo)){
							mp=j;
							mq=0;
							minn1=a[j][ij];
							
						}
						if(j!=ij&&sum[j]<=(2-bo)&&sum[ij]<=(2-bo)&&minn1<a[j][ij]){
							minn1=a[j][ij];
							mp=j;
							mq=ij;
						}
					}
					
				}
			}
			if(minn<minn1){
				ncnt++;
				sum[sz[ncnt].a]++;
				sum[sz[ncnt].b]++;
				if(sum[sz[ncnt].a]==3||sum[sz[ncnt].b]==3){
					bo=1;
				}
				 
				dp[i][ii]=dp[i-1][ii]+minn;
			}
			else{
				dp[i][ii]=dp[i-1][ii]+minn1;
				sum[mp]++;
				sum[mq]++;
				if(sum[mp]==3||sum[mq]==3){
					bo=1;
				}
			}
		}
	}
	int ans=maxn;
	for(int i=0;i<=(1<<k)-1;i++){
		if(ans<=dp[n][i]){
		}
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
} 
