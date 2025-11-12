#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans=0;
string s;
int c[505];
int n,m;                             
void dfs(int start,int total,int cs){
	if(total>=m){
		ans++;
	}
	for(int j=start+1;j<=n;j++){
		if(s[j-1]=='1'&&cs-total<c[j]){dfs(j,total+1,cs+1);}
		else{dfs(j,total,cs+1);};
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<ans%998244353;
	return 0;
}