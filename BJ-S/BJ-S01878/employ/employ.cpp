#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],p[501],ans;
string s;
bool use[501];
void ms(){
	int i,cnt=0,fq=0;
	for(i=0;i<n;i++){
		if(s[i]=='1'&&fq<c[p[i+1]])cnt++,fq=0;
		else fq++;
	}
	if(cnt==m)ans++,ans%=998244353;
	return;
}
void dfs(int dep){
	if(dep==n+1){
		ms();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			p[dep]=i;
			dfs(dep+1);
			use[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
