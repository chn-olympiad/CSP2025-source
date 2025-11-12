#include<bits/stdc++.h>
using namespace std;
int n,m,c[507],a[507],cnt;
long long ans,mod=998244353;
string s;
long long cj(long long x){
	long long y=1;
	if(x==0){
		return 1;
	}
	while(x>=1){
		y*=x;
		y%=mod;
		x--;
	}
	return y;
}
void dfs(int u,int v){
	if(cnt==m){
		ans+=cj(n-u+1);
		ans%=mod;
		return;
	}
	if(u>n)return;
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		a[i]=1;
		if(s[u-1]=='0'||c[i]<=v){
			dfs(u+1,v+1);
		}else{
			cnt++;
			dfs(u+1,v);
			cnt--;
		}
		a[i]=0;
	}
}
int main(){
	freopen("employ.in",'r',stdin);
	freopen("employ.out",'w',stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
