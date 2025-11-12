#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],x[505],p,t,ans;
string s;
bool b;
void dfs(int k,int q){
	if(k==n){
		if(q<=n-m)ans=(ans+1)%998244353;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!x[i]){
			x[i]=1;
			if((s[k]==0)||(c[i]<=q)){
				dfs(k+1,q+1);
			}
			else dfs(k+1,q);
			x[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])t++;
	}
	sort(c+1,c+n+1);
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')p++;
		else b=1;
	}
	if(p<m||n-t<m){cout<<0;return 0;}
	dfs(0,0);
	cout<<ans;
	return 0;
}
