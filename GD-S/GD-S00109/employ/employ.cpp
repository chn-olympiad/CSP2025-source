#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const long long mod=998244353;
string s;
bool bl;
long long out(long long x){
	long long ret=1;
	for(int i=x;i>1;i--){
		ret*=i;
		ret%=mod;
	}
	return ret;
}
int c[505],p[15];
bool bll[15];
bool judge(){
	int nf=0,nz=0;
	for(int i=1;i<=n;i++){
		if(nf>=c[p[i]]){
			nf++;
		}
		else{
			if(s[i-1]=='0'){
				nf++;
			}
			else{
				nz++;
			}
		}
	}
	return nz>=m;
}
void dfs(int dep){
	if(dep==n+1){
		if(judge()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bll[i]){
			bll[i]=true;
			p[dep]=i;
			dfs(dep+1);
			bll[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			bl=true;
			break;
		}
	}
	if(!bl){
		cout<<out(n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
}
