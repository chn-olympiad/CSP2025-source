#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int s[100005][4],n,t,ans;
void dfs(int now,int x,int a,int b,int c){
	if(x>n){
		ans=max(ans,now);
		return ;
	}
	if(a<n/2)dfs(now+s[x][1],x+1,a+1,b,c);
	if(b<n/2)dfs(now+s[x][2],x+1,a,b+1,c);
	if(c<n/2)dfs(now+s[x][3],x+1,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.txt","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i][1]>>s[i][2]>>s[i][3];
		if(n>10){
			int id;
			if(s[1][1])id=1;
			else if(s[1][2])id=2;
			else id=3;
			vector<int>vc;
			for(int i=1;i<=n;++i)vc.push_back(s[i][id]);
			sort(vc.begin(),vc.end());
			int ans=0;
			for(int i=vc.size();i>=1;--i)ans+=vc[i-1];
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,1,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
