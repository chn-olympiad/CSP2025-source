#include<bits/stdc++.h>
using namespace std;
int q[100001][5];
int a[1000001],b[1000001],c[1000001],vis[101],sum[1000001],summ[1000001],summm[1000001];
int cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--){
		long long ans=0;
		int n,cnt=0,cntt=0,cnttt=0;
		scanf("%d",&n);
		vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
		for(int i=1;i<=n;i++){
			if(q[i][0]>=max(q[i][1],q[i][2])){
				ans+=q[i][0];
				vis[0]++;
				sum[++cnt]=q[i][0]-max(q[i][1],q[i][2]);
			}
			else if(q[i][1]>=max(q[i][0],q[i][2])){
				ans+=q[i][1];
				summ[++cntt]=q[i][1]-max(q[i][0],q[i][2]);
				vis[1]++;
			}
			else{
				ans+=q[i][2];
				summm[++cnttt]=q[i][2]-max(q[i][1],q[i][0]);
				vis[2]++;
			}
		}
		sort(sum+1,sum+cnt+1,cmp);
		sort(summ+1,summ+cntt+1,cmp);
		sort(summm+1,summm+cnttt+1,cmp);
		if(vis[0]>n/2){
			for(int i=1;i<=vis[0]-n/2;i++){
				ans-=sum[i];
			}
		}
		if(vis[1]>n/2){
			for(int i=1;i<=vis[1]-n/2;i++){
				ans-=summ[i];
			}
		}
		if(vis[2]>n/2){
			for(int i=1;i<=vis[2]-n/2;i++){
				ans-=summm[i];
			}
		}				
		printf("%lld\n",ans); 
	}
} 
