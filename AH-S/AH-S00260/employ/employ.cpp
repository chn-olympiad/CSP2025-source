#include<iostream>
using namespace std;
typedef long long LL;
const LL N=505,mod=998244353;
int n,m,cnt;
string s;
int c[N];
bool vis[N];
void dfs(int u,int v,int w){
	if(u==n+1){
		if(v>=m){
			cnt++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if((w<c[i])&&(s[u]=='1')){
				dfs(u+1,v+1,w);
			}else{
				dfs(u+1,v,w+1);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<cnt<<"\n";
	return 0;
}
