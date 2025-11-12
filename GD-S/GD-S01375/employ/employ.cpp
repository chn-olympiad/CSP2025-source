#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int c[510],h[510];
bool vis[100010];
int p[100010];
int cnt=0;
void dfs(int k){
	if(k==n+1){
		int res=0,pp=0;
		for (int i=1;i<=n;i++){
			if(h[i]==0) res++;
			//cout<<res<<' ';
			if(c[p[i]]>res) {
				//cout<<"fu"<<'\n';
				pp++;
			}
		}
		if(pp>=m) cnt++;
	}
	for (int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=m;i++){
		cin>>c[i];
	}
	for (int i=1;i<s.size();i++){
		if(s[i]=='1') {
			cnt++;
			h[i]=1;
		}
		else h[i]=0; 
	}
	if(cnt==0){
		cout<<0<<'\n';
		return 0;
	}
	else {
		dfs(1);
		cout<<cnt<<'\n';
	}
	return 0;
}
