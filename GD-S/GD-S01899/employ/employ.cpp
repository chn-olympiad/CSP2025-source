#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[510],vis[510],tot[510],cc[510];
string s;
ll ans=0;
void dfs(int x,int c){
	if(n-x+1<m-c)return ;
	if(x>n){
		if(c>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,c+((a[i]>=x-c)&&(s[x]=='1')));
			vis[i]=0;
		}
	}
}
ll f[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot[i]=tot[i-1]+'1'-s[i]; 
//		cout<<tot[i]<<" ";
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%mod;
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans;
	}
	else{
		cout<<0; 
	}
	return 0;
}
/*
10 0
1111111111
1 1 1 1 1 1 1 1 1 1
*/
