#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
bool bz;
bool vis[5005];
int cnt;
int zuhe[5005][5005];
void dfs(int mx,int cur,int ans,int x){
	if(cur==n+1){
		if(ans>2*mx&&x>=3){
			cnt++;
			cnt%=MOD;
		}
		return;
	}
	dfs(max(mx,a[cur]),cur+1,ans+a[cur],x+1);
	dfs(mx,cur+1,ans,x);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			bz=1;
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=i;j++){
			if(i==1||j==1||(j==n&&i!=n+1)){
				zuhe[i][j]=1;
			}else{
				zuhe[i][j]=(zuhe[i-1][j]+zuhe[i-1][j-1])%MOD;
			}
		}
	}
	if(bz==0){
		long long p=0;
		for(int i=3;i<=n;i++){
			p+=zuhe[n+1][i+1];
		}
		cout<<p<<endl;
		return 0;
	}
	dfs(0,1,0,0);
	cout<<cnt%MOD;
	return 0;
}


