#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[25],vis[25],a[25],ans=0;
string s;
void dfs(int u){
	if(u>n){
		int l=0,x=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				if(c[a[i]]>l)x++;
				else l++;
			}
			if(s[i]=='0'){
				l++;
			}
		}
		if(x>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[i]=u;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='#'+s;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	if(n<=18){
		dfs(1); 
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		long long ans2=1;
		for(int i=1;i<=n;i++){
			ans2=ans2*i*1LL;
			ans2%=mod;
		}
		cout<<ans2<<'\n';
	}
}
