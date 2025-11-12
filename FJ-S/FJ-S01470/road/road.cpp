#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int u[100005],v[100005],d[100005];
int dp[100005];
int c[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>d[i];
	}
	for(int j=0;j<k;j++){
		cin>>c[j];
		for(int i=0;i<m;i++){
			cin>>a[i];
			a[i]+=c[i]; 
		}
	} 
	//擂台找到最小修复费用（最高优先级），其次有相同城市串联（其次优先级），二分（最低优先级）  
	int minn=INT_MAX,num;
	for(int i=0;i<m;i++){//一次性切入 
		if(minn>d[i]){
			minn=d[i];
			num=i;
		}
	}
	ans+=minn;
	dp[u[num]]=1,dp[v[num]]=1;
	int sum=1;//判断是否全部串联
	while(sum!=0){//是否串联完成 
		for(int i=0;i<m;i++){
			if(u[num]==u[i]&&v[num]!=v[i]&&dp[v[i]]!=1){//城市串联，但保证不重复 1:1
				ans+=d[i];
				//cout<<d[i]<<" ";
				dp[v[i]]=1;
				num=i;
				//cout<<dp[v[i]]<<" "<<u[i]<<" "<<v[i]<<endl;
			}
			if(u[num]==v[i]&&v[num]!=u[i]&&dp[u[i]]!=1){//1：2 
				ans+=d[i];
				//cout<<d[i]<<" ";
				dp[u[i]]=1;
				num=i;
				//cout<<dp[u[i]]<<" "<<u[i]<<" "<<v[i]<<endl;
			}
			if(v[num]==u[i]&&u[num]!=v[i]&&dp[v[i]]!=1){//2:1
				ans+=d[i];
				//cout<<d[i]<<" ";
				dp[v[i]]=1;
				num=i;
				//cout<<dp[v[i]]<<" "<<u[i]<<" "<<v[i]<<endl;
			}
			if(v[num]==v[i]&&u[num]!=u[i]&&dp[u[i]]!=1){//2:2
				ans+=d[i];
				//cout<<d[i]<<" ";
				dp[u[i]]=1;
				num=i;
				//cout<<dp[u[i]]<<" "<<u[i]<<" "<<v[i]<<endl;
			}
		}
		//cout<<endl<<endl;
		int count;
		for(int i=1;i<=n;i++){//检验是否全部串联 
			if(dp[i]==0){
				sum=1;
			}
			if(dp[i]==1){
				count++;
			}
			if(count==n){
				sum=0;
			}
		//	cout<<dp[i]<<" ";
		}
		count=0;
	}
	cout<<ans; 
	return 0;
}
