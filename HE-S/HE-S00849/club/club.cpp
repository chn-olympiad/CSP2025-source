#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[110000][4],sum[4];
int ans=0,ma=INT_MIN;
bool vis[110000];
inline void dfs(int ans,int s){
	if(s==n){
		ma=max(ma,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(vis[i]){
				break;
			}
			if(!vis[i]&&sum[j]<n/2){
				vis[i]=true;
				sum[j]++;
				dfs(ans+a[i][j],s+1);
				vis[i]=false;
				sum[j]--;
			}
		}
	}
	
}
inline void solve(){
	ans=0,ma=INT_MIN;
	int maa=INT_MIN,mbb=INT_MIN,flag,flag2,maa2=INT_MIN,mbb2=INT_MIN;
	bool f=false,ff=false;
	memset(sum,0,sizeof sum);
	memset(vis,false,sizeof vis);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][2]>0) f=true;
			if(a[i][3]>0) ff=true;
			if(j==1){
				if(a[i][1]>maa){
					maa=a[i][1];
					flag=i;
				}else if(a[i][1]>maa2) maa2=a[i][1];
			}
			if(j==2){
				if(a[i][2]>mbb){
					mbb=a[i][2];
					flag2=i;
				}else if(a[i][2]>mbb2) mbb2=a[i][2];
			}
			
		}
	}
	if(!f&&!ff){
		cout<<maa<<'\n';
		return;
	}else if(!ff){
		cout<<maa<<" "<<maa2<<" "<<mbb<<" "<<mbb2<<'\n';
		if(flag!=flag2){
			cout<<maa+mbb<<'\n';
		}else{
			cout<<max(maa+mbb2,maa2+mbb)<<'\n';
		}
		return ;
	}
	dfs(0,0);
	cout<<ma<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
