#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m;
string s;
int c[505],ans=0;
long long jie(int n){
	long long ret=1;
	for(int i=1;i<=n;i++){
		ret=(ret*i)%MOD; 
	}
	return ret;
}
bool vis[50];
int peo[50];
int check(){
	int nm=0,nc=0;
	for(int i=1;i<=n;i++){
		if(nc>=c[peo[i]]) continue;
		if(s[i-1]=='0') nc++;
		else nm++;
	}
	if(nm>=m) return 1;
	return 0;
}
void dfs(int t){
	if(t>n){
		ans+=check();
		ans=ans%MOD;
	//	for(int i=1;i<=n;i++) cout<<peo[i];
	//	cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			peo[t]=i;
			vis[i]=true;
			dfs(t+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	if(n<15){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n==m){
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]==0){
				cout<<"0";
				return 0;
			}
		}
		cout<<jie(n-cnt)*jie(cnt)%MOD;
	}else{
		cout<<jie(n-cnt)*jie(cnt)%MOD;
	}
	return 0;
}
