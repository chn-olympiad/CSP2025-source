#include<bits/stdc++.h>
using namespace std;
const int N=5000,mod=998244353;
int n,a[N+1],maxa=0;
long long cnt=0;
void dfs(int idx,int c,int sum){
	if(c>=3){
		if(sum>a[idx]*2)cnt=(cnt+1)%mod;
	}
	for(int i=idx+1;i<=n;i++){
		dfs(i,c+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){
		long long f[501][501],ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)f[i][1]=1;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=i;j++){
				for(int k=1;k<i;k++){
					f[i][j]=(f[i][j]+f[k][j-1])%mod;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<f[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for(int i=3;i<=n;i++){
			for(int j=3;j<=i;j++){
				ans=(ans+f[i][j])%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
