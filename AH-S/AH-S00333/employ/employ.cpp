#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,mod=998244353,c[501],b[501],ans,d[501];
string a;
void dfs(int x){
	if(x==n+1){
		int t=0,o=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0')o++;
			else if(c[d[i]]<=o)o++;
			else t++;
		}
		if(t>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			d[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	a=" "+a;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==1){
		long long s=1;
		for(int i=1;i<=n;i++)s=s*i%mod;
		cout<<s;
	}else if(m==n){
		long long s=1;
		for(int i=1;i<=n;i++){
			s=s*i%mod;
			if(a[i]=='0'){
				s=0;
				break;
			}
		}
		cout<<s;
	}else if(n<=10){
		dfs(1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++;
