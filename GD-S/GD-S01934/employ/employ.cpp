#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
long long ans;
bool b[501]={0};
string s;
void dfs(int ac,int wa,int x){
	if(n-x<m-ac) return;
	if(x==n){
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1;
			if(s[x]=='0' || wa>=c[i]) dfs(ac,wa+1,x+1);
			else dfs(ac+1,wa,x+1);
			b[i]=0;
		}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(!s.find('0')){
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
	}
	else{
		ans=0;
		dfs(0,0,0);
	}
	cout<<ans;
	return 0;
}
