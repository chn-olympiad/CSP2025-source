 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T,n,a[N][4],ans=-1,vis[4],b[N];
void dfs(int dp,int cnt){
	if(dp>n){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<(n/2)){
			vis[i]++;
			dfs(dp+1,cnt+a[dp][i]);
			vis[i]--; 
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool ch=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i]=a[i][1];
				if(a[i][2]!=0||a[i][3]!=0)ch=1; 
			}
		}
		if(ch)dfs(1,0);
		else {
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}
		cout<<ans<<endl;
	}
} 
