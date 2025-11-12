#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m;
bool s[N];
int c[N];
int ans;
int cs[N];
bool vis[N];
void dfs(int k,int sum){
	if(k>n){
//		int sum=0;
//		for(int i=1;i<=n;i++){
//			cout<<cs[i]<<" ";
////			if(s[i]&&(i-1-sum)<c[cs[i]]){
////				sum++;
////			}
//		}
//			cout<<sum<<" "<<endl;
		if(sum>=m){
			ans=(ans+1)%MOD;
		}
		return;
	}
	if(sum+(n-k+1)<m)return;
//	cout<<k<<endl;
//	cout<<string(k,'-')<<k<<" "<<sum<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		cs[k]=i;
		vis[i]=1;
//		cout<<i<<" ";
		if(s[k]&&k-1-sum<c[i]){
//			cout<<string(k,'-')<<k<<" "<<i<<" "<<1<<endl;
			dfs(k+1,sum+1);
		}else{
//			cout<<string(k,'-')<<k<<" "<<i<<" "<<2<<endl;
			dfs(k+1,sum);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
}

