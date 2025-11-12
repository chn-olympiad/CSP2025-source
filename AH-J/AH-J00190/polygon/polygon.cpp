#include<iostream>
using namespace std;
int n,a[5010],cnt,dp[5001][5001],q[5010];
void dfs(int x,int m,int maxn,int s){
	for(int i=x-1;i>=1;i--){
		if(s>=2){
			if(a[x]+m>maxn){
				cnt=cnt+((i-1)*i)/2+1;
				return;
			}
		}
		dfs(i,m+a[x],maxn,s+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int d=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			d++;
		}
		q[i]=q[i-1]+a[i];
	}
	if(d==n){
		cout<<n*(n+1)/2-n-n*(n-1)/2;
		return 0;
	}
	for(int i=n;i>=3;i--){
		dfs(i,0,a[i],1);
	}
	cout<<cnt;
	return 0;
}
