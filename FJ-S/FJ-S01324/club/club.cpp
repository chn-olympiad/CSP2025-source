#include<bits/stdc++.h>
using namespace std;
long long t,n,aa[100101][6],jk[5],p,k,ans,dp[101010][6],vis[301012],dis[5],op; 
long long a[100111],b[101001],c[101010];
void DJ(int u){
	if(u>n){
		op=max(op,ans);
		return ;
	}
	for(int j=1;j<=3;j++){
		if(jk[j]<n/2){
			ans+=aa[u][j];
			jk[j]++;
			DJ(u+1);
			jk[j]--;
			ans-=aa[u][j];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		op=0;
		ans=0;
		memset(vis,0,sizeof(vis));
		
		for(int i=0;i<=2;i++){
			dis[i]=0;
		}
		ans=0;
		scanf("%lld",&n);
		if(n<=15){
			for(int i=1;i<=n;i++){
				scanf("%lld%lld%lld",&aa[i][1],&aa[i][2],&aa[i][3]);
				
			}
			DJ(1);	
			cout<<op<<" "<<endl;	
		}
		else {
			for(int i=1;i<=n*3;i++){
				cin>>a[i];
				
			}
			sort(a+1,a+1+n*3);
			for(int i=n*2+1;i<=n*3;i++){
				ans=a[i]+ans; 
			}
			cout<<ans<<endl;
		}
//		sort(aa+1,aa+1+(3*n),cmp);
//		for(int i=3*n;i>=1;i--){
//			if(vis[i]!=0&&dis[aa[i].op]>(n/2)){
//				ans+=aa[i].a;
//				dis[aa[i].op]++;
//				vis[i]=1;
//			}
//		}	
//		
//		printf("%lld\n",ans);
		//priority_queue<int > q_,q__,q___;
		
		
		
	}
	return 0;
} 
