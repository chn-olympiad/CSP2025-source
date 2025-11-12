#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N=1e5+5;
int n,m,c[N];
int ans=0;
string s;

void dfs(int ceng,int tot,int nandu,int dis){
	if(ceng==n+1){
		ans=(ans+1)%mod;
		return ;
	}
	
	if(nandu==1){
		if(dis<=c[ceng]){
			dfs(ceng+1,tot+1,nandu,dis);
		}
		else{
			dfs(ceng+1,tot+1,nandu,dis+1);
		}
	}
	else {
		dfs(ceng+1,tot,nandu,dis+1);
	}
	return ;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int len=s.size();
	for(int i=0;i<len;i++){
		dfs(1,0,s[i],0);
	}
	cout<<ans;
	return 0;
}