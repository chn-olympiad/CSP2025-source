#include<iostream>
using namespace std;
const int MOD=998244353;
int n,m;
string str;
int c[510];
int p[510];
bool vis[510];
int ans=0;
int dp[(1<<18)+10][20];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i-1-cnt<c[p[i]]&&str[i]=='1'){
			cnt++;
			if(cnt==m){
				return true;
			}
		}
	}
	return false;
}
void dfs(int x){
	if(x>n){
		ans=(ans+check())%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;str="#"+str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}