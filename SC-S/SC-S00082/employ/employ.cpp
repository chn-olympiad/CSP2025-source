#include<bits/stdc++.h>
using namespace std;
const int MAXN=500,MOD=998244353;
int n,m;
string s;
int c[MAXN];
int a[MAXN];
bool vis[MAXN];
int cnt,ans;
void dfs(int step){
	if(step>n){
		cnt=0;	
//		for(int i=1;i<=n;i++) cout<<a[i];		
		for(int i=0;i<n;i++){
			if(i-cnt>=c[a[i+1]]) continue ;
			if(s[i]=='1') cnt++;
			if(cnt>=m){
				ans=(ans+1)%MOD;
				return ;
			}
//			printf("(%d)",cnt);
		}
//		cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='1') cnt++;
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(cnt==n){
		ans=1;
		for(int i=n;i>=1;i--)
			ans=ans*i%MOD;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		vis[i]=0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}