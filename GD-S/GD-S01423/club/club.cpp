#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,cnt;
int a[N],c[4][N],vis[4];
bool fa=1,fb=1;
void dfs(int d){
	if(d>n){
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=c[a[i]][i];
		}
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>=n/2) continue;
		vis[i]++;
		a[d]=i;
		dfs(d+1);
		vis[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		fa=1,fb=1;
		for(int i=1;i<=n;i++){
			cin>>c[1][i]>>c[2][i]>>c[3][i];
			if(c[3][i]) fa=0,fb=0;
			else if(c[2][i]) fa=0;
		}
		cout<<fa<<fb<<endl;
		if(fa){
			sort(c[1]+1,c[1]+1+n);
			for(int i=1;i<=n/2;i++) ans+=c[1][i];
			cout<<ans<<endl;
			continue;
		}
		else if(fb){
			sort(c[1]+1,c[1]+1+n);
			sort(c[2]+1,c[2]+1+n);
			for(int i=n;i>n/2;i--) ans+=max(c[1][i],c[2][i]);
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
