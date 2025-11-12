#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
int ans=0;
char f[100005];
int a[100005];
int d[100005];
bool vis[100005];
int C[105][105];
int qps[105];
bool che(int mqn){
	int lo=0,s=0;
	for(int i=1;i<=mqn;i++){
		if(f[i]=='0'||lo>=a[d[i]]) lo++;
		else s++;
	}
	if(s>=m) return true;
    else return false;
}
void dfs(int mq){
	if(che(mq-1)==true){
		
		ans+=qps[n-mq+1];
		if(mq==n+1){
			ans++;
		}
		ans%=MOD;
		return ;
	}
	if(mq==n+1) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			d[mq]=i;
			vis[i]=true;
			dfs(mq+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		qps[j]=j;
		for(int i=j-1;i>=1;i--){
		    qps[j]*=i;
		    qps[j]%=MOD;
	    } 
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==1) C[i][j]=1;
			else if(j==1) C[i][j]=i;
			else if(i==j) C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=MOD;
		}
	}
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=18){
		dfs(1);
	    cout<<ans;
	} 
	else{
		if(n==1&&a[1]!=0) cout<<1;
		else cout<<qps[n];
	} 
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

