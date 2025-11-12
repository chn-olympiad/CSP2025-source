#include <bits/stdc++.h>
using namespace std;
int p[100010][4]={};
int ans=0;
int n;
int rs[4]={};
void dfs(int index,int group,int s){
	rs[group]++;
	s+=p[index][group];
	if (index==n){
		ans=max(ans,s);
		return;
	}
	for (int i=1;i<=3;i++){
		if (rs[i]+1<=(n/2)){
			dfs(index+1,i,s);
			rs[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--){
		memset(p,0,sizeof(p));
		memset(rs,0,sizeof(rs));
		ans=0; 
		cin>>n;
		for (int i=1;i<=n;i++) cin>>p[i][1]>>p[i][2]>>p[i][3];
		for (int i=1;i<=3;i++){
			dfs(1,i,0);
			rs[i]--;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
