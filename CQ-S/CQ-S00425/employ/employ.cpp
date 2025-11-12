#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
#define PII pair<int,int>
#define tp tuple<int,int,int>
#define fi(x) (x.first)
#define se(x) (x.second)
int n,m,a[505],res,sum[505],xu[505],vis[505],is1=1;
string s;
const int MOD=998244353;
void dfs(int pos){
	if(pos>n){
		int ans=0,k=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&a[xu[i]]>k) ans++;
			else k++;
		}
		if(ans>=m) res++;
		res%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,xu[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	I n >> m;
	I s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		I a[i];
		if(a[i]!=1) is1=0;
	}
	dfs(1);
	O res;
	return 0;
}
