#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,num[3]={0,0,0};
vector<vector<int> > m;
void dfs(int x,int res){
	if(x>n){
		ans=max(ans,res);
		return ;
	}
	for(int i=0;i<3;i++){
		if(num[i]<n/2){
			res+=m[x][i];
			num[i]++;
			dfs(x+1,res);
			res-=m[x][i];
			num[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		m.clear();
		ans=0;
		cin>>n;
		m.resize(n+1,vector<int>(3,0));
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>m[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
