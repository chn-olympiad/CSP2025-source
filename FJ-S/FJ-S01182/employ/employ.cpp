#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],len,fac[505],ans;
string s;
bool fl[505];
void dfs(int d,int x){
	if(d==n){
		if(n-x>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(fl[i]) continue;
		fl[i]=1;
		if(x>=c[i]||s[d]=='0') dfs(d+1,x+1);
		else dfs(d+1,x);
		fl[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;i++) fac[i]=(i*fac[i-1])%mod;
	cin>>n>>m>>s;
	len=s.size();
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	if(n==m){
		bool fl=1;
		for(int i=0;i<len;i++){
			if(s[i]=='0') {fl=0;break;}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				fl=0;
				break;
			}
		}
		if(!fl) cout<<0;
		else{
			cout<<fac[n];
		}
		return 0;
	}
	if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0) cnt++;
		}
		if(cnt==n) cout<<0;
		else cout<<fac[n-cnt];
		return 0;
	}
	cout<<0;
	return 0;
}