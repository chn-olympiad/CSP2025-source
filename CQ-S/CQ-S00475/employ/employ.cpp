#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,a[N],h[N],vis[N],ans;
string s;
void dfs(int x){
	if(x==n+1){
		int sum=0,l_sum=0;
		for(int i=1;i<=n;i++){
//			cerr<<h[i]<<' ';
			if(l_sum>=a[h[i]]||s[i]=='0'){
				l_sum++;
			}else{
				sum++;
			}
		}
//		cerr<<'\n'<<sum<<'\n';
		ans=(ans+(sum>=m))%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			h[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			h[x]=0;
		}
	}
}
int main(){
	fstream cin("employ.in",ios::in);
	fstream cout("employ.out",ios::out);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s.insert(s.begin(),'#');
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}

