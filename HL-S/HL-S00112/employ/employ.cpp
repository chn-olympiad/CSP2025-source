#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m;
string s;
int c[550];
int tu[550],vis[550];
int p;

bool check(){
	int cnt=0,giv=0;
	for(int i=1;i<=n;i++){
		//cout<<tu[i]<<' ';
		int k=tu[i];
		if(giv>=c[k]||s[i-1]=='0'){
		//	if(giv>=c[k]) cout<<"fuck "<<k<<'\n';
			//if(s[i]=='0') cout<<"can "<<k<<'\n';
			giv++;continue;
		}
		cnt++;
	}
//	cout<<'\n';
	return cnt>=m;
}

void dfs(int k){
	if(k>=n){
		if(check()) p=(p+1)%Mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			tu[++k]=i;
			vis[i]=1;
			dfs(k);
			tu[k--]=0;
			vis[i]=0;
		}
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>s;
	if(n==m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0);
	cout<<p;
	return 0;
}
