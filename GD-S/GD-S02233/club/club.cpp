#include<bits/stdc++.h>
using namespace std;

int a[100005][4];
int n,ml;
bool vis[100005][4];

struct yi{
	int nw,qa,qb,qc,sy;
};
queue<yi> q;
//int dp[100005][4];//第i个人去j时能获得的最大收益 


void sol(){
	long long ans=-1e9;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	ml=n/2;
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			vis[i][j]=0;
		}
	} 
//	cout<<endl<<endl;
//	dp[1][1]=a[1][1];
//	dp[1][2]=a[1][2];
//	dp[1][3]=a[1][3];

	q.push({0,0,0,0,0});
	
	while(!q.empty()){
		yi k=q.front();
		
		q.pop();
		if(k.nw==n){
			ans=max(ans,(long long)k.sy);
			
			continue;
		}
//		cout<<k.nw<<" "<<k.qa<<" "<<k.qb<<" "<<k.qc<<" "<<endl;
//		cout<<k.nw<<endl;
		if(k.qa<ml){
			if(!vis[k.nw+1][1])
				q.push({k.nw+1, k.qa+1, k.qb, k.qc, k.sy+a[k.nw+1][1]});
		}
		if(k.qb<ml){
			if(!vis[k.nw+1][2])
				q.push({k.nw+1, k.qa, k.qb+1, k.qc, k.sy+a[k.nw+1][2]});
		}
		if(k.qc<ml){
			if(!vis[k.nw+1][3])
				q.push({k.nw+1, k.qa, k.qb, k.qc+1, k.sy+a[k.nw+1][3]});
		}
		
	}
	
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++){
//		dp[i][]=
//	} 
}

int main(){
//	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;cin>>T;
	while(T--) sol();
} 
