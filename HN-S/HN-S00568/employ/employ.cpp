#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,a[510],b[510],ans,v[510],flg;
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0,k=0;
		for(int i=1;i<=n;i++){
			if(b[i]<=cnt||s[i]=='0')cnt++;
			else k++;
			k=k%MOD;
		}
		if(k>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;b[x]=a[i];
			dfs(x+1);
			v[i]=0;b[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}


