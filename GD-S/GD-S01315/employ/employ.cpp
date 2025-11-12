#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m;
char s[10005];
int c[10005];
bool vis[1005];
int ans;
void dfs(int cur,int i){
	if(n-cur<m)return;
	if(i==n+1){
		ans++;
		return;
	}
	for(int j=1;j<=n;j++){
		if(vis[j])continue;
		vis[j]=true;
		if(s[i]=='0'||c[j]<=cur)dfs(cur+1,i+1);
		else dfs(cur,i+1);
		vis[j]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	bool f=true;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')f=false;
	}
	int num1=0;
	for(int i=1;i<=n;i++)cin>>c[i],num1+=(c[i]==0?1:0);
	if(n-num1<m){
		cout<<0;
	}else if(f){
		if(n-num1>=m){
			long long ans=1;
			for(int i=2;i<=n;i++){
				ans*=i;
				ans%=MOD;
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else{
		dfs(0,1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
