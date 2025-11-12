#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505];
bool b[505];
string t;
int n,m;
int ans=0;
void dfs(int c,int s,int p){
	if(p>n){
		if(s>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(t[p]=='0'||c>=a[i]) dfs(c+1,s,p+1);
			else dfs(c,s+1,p+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	t=" "+t;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

