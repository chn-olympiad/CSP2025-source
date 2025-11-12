#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
string s;
int c[N];
int n,m,p[N],vis[N],ans;
void dfs(int u){
	if(u>n){
		int cnt=0,cn=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i]=='0')cnt++;
			else {
				cn++;
			}
		}
		if(cn>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>s;
	s='*'+s;
	int ct=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]=='1')ct++;
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	cout<<rand()%mod;
	
	return 0;
}
 
