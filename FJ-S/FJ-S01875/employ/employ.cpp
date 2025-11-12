#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510];
bool vis[510];
long long ans=0;
string str;
void dfs(int day,int loser,bool vis[510]){
	if(loser>(n-m))return ;
	if(day>=n){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(loser>=c[i]){
			vis[i]=1;
			dfs(day+1,loser+1,vis);
			vis[i]=0;
		}
		else if(str[day]=='0'){
			vis[i]=1;
			dfs(day+1,loser+1,vis);
			vis[i]=0;		
		}
		else{
			vis[i]=1;
			dfs(day+1,loser,vis);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>str;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(0,0,vis); 
	printf("%lld",ans);
	return 0;
}

