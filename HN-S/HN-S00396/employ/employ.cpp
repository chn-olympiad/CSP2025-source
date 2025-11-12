#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll sum;
int n,m,c[510],qz[510],sz;
bool vis[510];
char s[510];
void dfs(int k,int i,int cnt){
	if(!k){
		if(cnt>=m){
			sum=(sum+1)%mod;
		}
		return;
	}
	if(i>n)	return;
	for(int j=1;j<=n;j++){
		if(vis[j])	continue;
		vis[j]=1;
		dfs(k-1,i+1,cnt+(qz[i]<c[j]));
		vis[j]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		qz[i+1]=qz[i]+s[i]-'0';
		sz+=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		int yh[510][510];
		for(int i=0;i<=n;i++){
			yh[i][0]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			}
		}
		cout<<yh[n][n];
		return 0;
	}
	sort(c+1,c+1+n);
	dfs(sz,1,0);
	cout<<sum;
	return 0;
}

