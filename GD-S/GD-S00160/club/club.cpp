#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+5;
int n,a[N],b[N],c[N],ans=0,dp[2][105][105][105];
void dfs(int now,int sum,int cnta,int cntb,int cntc){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnta<n/2)dfs(now+1,sum+a[now],cnta+1,cntb,cntc);
	if(cntb<n/2)dfs(now+1,sum+b[now],cnta,cntb+1,cntc);
	if(cntc<n/2)dfs(now+1,sum+c[now],cnta,cntb,cntc+1);
}
void solve(){
	memset(dp,0,sizeof(dp));
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		if(b[i]!=0||c[i]!=0){
			f=0;
			break;
		}
	}
	if(f){
		sort(a+1,a+1+n);
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<"\n";
		return;
	}
	if(n<=200){
		for(int i=1;i<=n;i++){
			for(int p=min(n/2,i);p>=0;p--){
				for(int q=min(n/2,i);q>=0;q--){
					int r=i-p-q;
					if(r<0||r>n/2)continue;
					if(p){
						dp[i%2][p][q][r]=max(dp[i%2][p][q][r],dp[(i-1)%2][p-1][q][r]+a[i]);
					}
					if(q){
						dp[i%2][p][q][r]=max(dp[i%2][p][q][r],dp[(i-1)%2][p][q-1][r]+b[i]);
					}
					if(r){
						dp[i%2][p][q][r]=max(dp[i%2][p][q][r],dp[(i-1)%2][p][q][r-1]+c[i]);
					}
				}
			}
		}
		for(int p=n/2;p>=0;p--){
			for(int q=n/2;q>=0;q--){
				int r=n-p-q;
				if(r<0||r>n/2)continue;
				ans=max(ans,dp[0][p][q][r]);
			}
		}
		cout<<ans;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
