#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,cost[N][5],ans=0,cnt[5],p[N];
void dfs(int u){
	if(u>n){
		int tot=0;
		for(int i=1;i<=n;i++){
			tot+=cost[i][p[i]];			
		}
		ans=max(tot,ans);
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1>(n/2))continue;
		p[u]=i;
		cnt[i]++;
		dfs(u+1);
		p[u]=0;
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		int tagA=1; 
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>cost[i][j];
			}
		}
		if(n<=10){
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(cost[i][2]!=0||cost[i][3]!=0)tagA=0;
		}
		if(tagA){
			vector<int>v;
			for(int i=1;i<=n;i++){
				v.push_back(cost[i][1]);
			}
			sort(v.begin(),v.end(),greater<int>());
			for(int i=0;i<(n/2);i++){
				ans+=v[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
 
