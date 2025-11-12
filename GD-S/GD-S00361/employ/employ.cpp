#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
bool f[N];
int n,m,c[N],s[N],a[N],ans=0;
int run(){
	int pass=0,out=0;
	for(int i=1;i<=n;i++){
		if(out>=c[a[i]]) out++;
		else if(s[i]==0) out++;
		else pass++;
	}
	return pass;
}
void dfs(int d){
	if(d==n){
		ans=(ans+int(run()>=m))%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!f[i]){
			a[d+1]=i, f[i]=true;
			dfs(d+1);
			a[d+1]=0, f[i]=false;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string str;
	cin>>n>>m>>str;
	bool A=true;
	for(int i=1;i<=n;i++) s[i]=int(str[i-1]-'0'), A&=(s[i]==1);
	for(int i=1;i<=n;i++) cin>>c[i];
	if(A){
		ans=1;
		for(int i=2;i<=n;i++) ans=(ans*i)%mod;
	}
	else dfs(0);
	cout<<ans<<"\n";
	return 0;
} 
