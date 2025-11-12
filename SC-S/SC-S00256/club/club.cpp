#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long t,n,tmp,cnt[5],ans,a[N][5],vis[N];
void dfs(int k){
	if(k>=n){
		ans=max(ans,tmp);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(cnt[j]+1<=n/2&&vis[i]==0){
				cnt[j]++;
				vis[i]=1;
				tmp+=a[i][j];
				dfs(k+1);
				cnt[j]--;
				vis[i]=0;
				tmp-=a[i][j];
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		memset(vis,0,sizeof vis);
		ans=0;
		tmp=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				tmp+=a[i][j];
				cnt[j]++;
				vis[i]=1;
				dfs(1);
				tmp=0;
				vis[i]=0;
				cnt[j]=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 