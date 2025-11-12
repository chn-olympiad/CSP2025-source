#include<bits/stdc++.h>
using namespace std;
int cl[100005][3];
int n;
long long maxs=INT_MIN;
void dfs(int num,int ac,int bc,int cc,long long sum){
	if(num>n){
		maxs=max(maxs,sum);
		return;
	}
	if(ac<n/2){
		sum+=cl[num][0];
		dfs(num+1,ac+1,bc,cc,sum);
		sum-=cl[num][0];
	}
	if(bc<n/2){
		sum+=cl[num][1];
		dfs(num+1,ac,bc+1,cc,sum);
		sum-=cl[num][1];
	}
	if(cc<n/2){
		sum+=cl[num][2];
		dfs(num+1,ac,bc,cc+1,sum);
		sum-=cl[num][2];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxs=INT_MIN;
		memset(cl,0,sizeof(cl));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i][0]>>cl[i][1]>>cl[i][2];
		}
		dfs(1,0,0,0,0);
		cout<<maxs<<endl;
	}
	return 0;
} 
