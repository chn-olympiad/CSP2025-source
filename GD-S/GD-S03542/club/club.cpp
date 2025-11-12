#include<bits/stdc++.h>
using namespace std;
const int M=2e2+233,N=1e5+233;
int T,n,v[N][5],w[N],dp[M][M][M],ans;
bool flag=0;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	memset(dp,0,sizeof(dp));
	memset(v,0,sizeof(v));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
		if(v[i][1] || v[i][2]) flag=1;
		w[i]=v[i][0];
	}
	if(flag && n<=10){
		for(int k=1;k<=n;k++){
			for(int i=n;i>=0;i--){
				for(int j=n;j>=0;j--){
					if(i+j>n) continue;
					if(i>0)
						dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j]+v[k][0]);
					if(j>0)
						dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j-1]+v[k][1]);
					if(n-i-j>0)
						dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j]+v[k][2]);
				}
			}
		}
		ans=0;
		for(int i=(n/2);i>=0;i--){
			for(int j=(n/2);j>=0;j--){
				if((n-i-j)>(n/2)) continue;
				ans=max(ans,dp[n][i][j]);
			}
		}
	}
	else if(flag){
		ans=0;
		for(int k=1;k<=(2e8/n);k++){
			int num[5]={},tmp=0;
			for(int i=n;i>=0;i--){
				int t=rand()%3;
				while(num[t]+1>(n/2)) t=rand()%3;
				num[t]++;
				tmp+=v[i][t];
			}
			ans=max(ans,tmp);
		}
	}
	else{
		ans=0;
		sort(w+1,w+1+n,cmp);
		for(int i=1;i<=(n/2);i++)
			ans+=w[i];
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(NULL));
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
