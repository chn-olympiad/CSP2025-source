#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int m,n;
int dp[N][4];
int a[N][4];
/*struct node{
	int id,num;
}a[N][4];*/
int ans=0;
/*bool cmp(node a,node b){
	return a.num>b.num;
}
int cnt[4];
node min1,min2,min3;
bool  vis[N];*/
void dfs(int sum,int num,int sum1,int sum2,int sum3){
	if(num==n+1){
		ans=max(sum,ans);
	}
	if(sum1+1<=m){
		dfs(sum+a[num][1],num+1,sum1+1,sum2,sum3);
	}
	if(sum2+1<=m){
		dfs(sum+a[num][2],num+1,sum1,sum2+1,sum3);
	}
	if(sum3+1<=m){
		dfs(sum+a[num][3],num+1,sum1,sum2,sum3+1);
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		m=n/2;
		dfs(0,0,0,0,0);
		/*priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q[4];
		 int ans=0;
		 for(int i=1;i<=n;i++){
		 	int o1=a[i][1].id;
		 	int o2=a[i][2].id;
		 	int o3=a[i][3].id;
		 	if(cnt[o1]+1<=m){
		 		cnt[o1]++;
		 		ans+=a[i][1].num;
		 		q[o1].push({a[i][1].num,i})
		 		vis[i]=1;
			}
		 	else{
		 		if(a[i][1].numkq[o1].top()first+{
		 			auto k=q.[o1].top();
		 			vis[k.second]=0;
		 			q.pop();
		 			q[o1].push({a[i][1].num,i})
		 			vis[i]=1;
				 }
			 }
			 
		 }*/
		 
		 cout<<ans<<"\n";
	}
	return 0;
}
