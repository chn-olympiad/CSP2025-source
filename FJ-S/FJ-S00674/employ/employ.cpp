#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],s[505],val[505];
bool vis[505];
long long ans;
string str;
void solve(){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) cnt++;
		else if(cnt>=c[val[i]]) cnt++;
		else res++;
	}
	if(res>=m) ans++;
}
void dfs(int pos){
	if(!pos){solve();return;}
	if(!vis[1]&&1<=n) vis[1]=1,val[pos]=1,dfs(pos-1),vis[1]=0,val[pos]=0;
	if(!vis[2]&&2<=n) vis[2]=1,val[pos]=2,dfs(pos-1),vis[2]=0,val[pos]=0;
	if(!vis[3]&&3<=n) vis[3]=1,val[pos]=3,dfs(pos-1),vis[3]=0,val[pos]=0;
	if(!vis[4]&&4<=n) vis[4]=1,val[pos]=4,dfs(pos-1),vis[4]=0,val[pos]=0;
	if(!vis[5]&&5<=n) vis[5]=1,val[pos]=5,dfs(pos-1),vis[5]=0,val[pos]=0;
	if(!vis[6]&&6<=n) vis[6]=1,val[pos]=6,dfs(pos-1),vis[6]=0,val[pos]=0;
	if(!vis[7]&&7<=n) vis[7]=1,val[pos]=7,dfs(pos-1),vis[7]=0,val[pos]=0;
	if(!vis[8]&&8<=n) vis[8]=1,val[pos]=8,dfs(pos-1),vis[8]=0,val[pos]=0;
	if(!vis[9]&&9<=n) vis[9]=1,val[pos]=9,dfs(pos-1),vis[9]=0,val[pos]=0;
	if(!vis[10]&&10<=n) vis[10]=1,val[pos]=10,dfs(pos-1),vis[10]=0,val[pos]=0;
	if(!vis[11]&&11<=n) vis[11]=1,val[pos]=11,dfs(pos-1),vis[11]=0,val[pos]=0;
	if(!vis[12]&&12<=n) vis[12]=1,val[pos]=12,dfs(pos-1),vis[12]=0,val[pos]=0;
	if(!vis[13]&&13<=n) vis[13]=1,val[pos]=13,dfs(pos-1),vis[13]=0,val[pos]=0;
	if(!vis[14]&&14<=n) vis[14]=1,val[pos]=14,dfs(pos-1),vis[14]=0,val[pos]=0;
	if(!vis[15]&&15<=n) vis[15]=1,val[pos]=15,dfs(pos-1),vis[15]=0,val[pos]=0;
	if(!vis[16]&&16<=n) vis[16]=1,val[pos]=16,dfs(pos-1),vis[16]=0,val[pos]=0;
	if(!vis[17]&&17<=n) vis[17]=1,val[pos]=17,dfs(pos-1),vis[17]=0,val[pos]=0;
	if(!vis[18]&&18<=n) vis[18]=1,val[pos]=18,dfs(pos-1),vis[18]=0,val[pos]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=0;i<n;i++) s[i+1]=str[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(n);cout<<ans;
}
