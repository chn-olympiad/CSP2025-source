#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,c[505],cnt1,ans;
bool v[505];
string s;
void dfs(int x,int ctn){
	if(x>=n){
		ans=(ans+((n-ctn)>=m))%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1;
			int t=ctn;
			if(ctn>=c[i]) t++;
			else t+=(s[x+1]=='0');
			dfs(x+1,t);
			v[i]=0;
		}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cnt1+=(s[i]=='1');
		cin>>c[i];
	}
	if(cnt1<m){
		cout<<0;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
