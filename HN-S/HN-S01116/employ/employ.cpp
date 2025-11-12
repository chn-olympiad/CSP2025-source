#include<bits/stdc++.h>
using namespace std;
int flag[501];
int n,m,c[501],td[501],tt,ans,fl=1;
long long jc[501];
string s;
void dfs(int u,int gt,int ls){
	if(m-gt>n-u+1) return ;
	if(gt==m){
		ans=(ans+jc[n-u+1])%998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		flag[i]=1;
		if(!td[u]||ls>=c[i]) dfs(u+1,gt,ls+1);
		else dfs(u+1,gt+1,ls);
		flag[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=500;i++) jc[i]=jc[i-1]*i%998244353;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i],td[i]=s[i-1]-'0',tt+=td[i],fl*=c[i];
    if(tt<m){cout<<0;return 0;}
    if(tt==n&&fl){cout<<jc[n];return 0;}
    sort(c+1,c+n+1);
    dfs(1,0,0);
    cout<<ans;
	return 0;
}
//die die die
//no patient,are you serious?
