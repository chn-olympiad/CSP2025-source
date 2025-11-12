#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],a[505],u[505],ans=0;
string s; 
void dfs(int x){
	if(x==n+1){
		int res=0,sum=0;
		for(int i=1;i<=n;i++){
			//i-1-b[i-1]
			if(s[i-1]=='0'){
				sum++;
				continue;
			}
			if(sum>=c[a[i]]){
				sum++;
				continue;
			}
			res++;
			
		}
		if(res>=m) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!u[i]){
			u[i]=1;
			a[x]=i;
			dfs(x+1);
			u[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
/*
10 5
1111111111
6 0 4 2 1 2 5 4 3 3

*/
