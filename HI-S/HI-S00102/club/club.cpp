#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],cnt[N];
long long ans;
void dfs(int x,long long int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	
	for(int i=1;i<=3;i++){
		if(cnt[i]>=n/2) continue;
		cnt[i]++;
		dfs(x+1,(long long)(sum+a[x][i]));
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
