#include<bits/stdc++.h>
using namespace std;
long long a[5005],c[2005][2005],ans,n;
void dfs(long long sum,long long maxn,int d,int l){
	if(sum>maxn*2&&l==1) ans++;
	if(d==n+1) return ;
	dfs(sum+a[d],max(maxn,a[d]),d+1,1);
	dfs(sum,maxn,d+1,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++) c[i][i]=1;
		for(int i=1;i<=n;i++) c[i][1]=i;
		for(int i=1;i<=n;i++){
			for(int j=2;j<i;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
		for(int i=3;i<=n;i++) ans+=c[n][i];
		cout<<ans%998244353;
	}else{
		dfs(0,0,1,0);
		cout<<ans%998244353;
	}
}
