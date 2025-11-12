#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,c[501],p[501],a[501],ans,b[501],mod=998244353;
string s;

bool ok(){
	for(int i=1;i<=n;i++){
		if(p[i]==0)return 0;
	}
	return 1;
}

void dfs(int f,int x,int a){
	if(f>n){
		if(x>=m)ans++;
		if(ans>=mod)ans-=mod;
		//cout << x<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			//cout << c[i]<<' '<<a[i]<<' '<<p[i]<<'\n';
			if(c[i]>a&&p[f]==1)dfs(f+1,x+1,a);
			else dfs(f+1,x,a+1);
			b[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		p[i]=s[i-1]-'0';
		//cout << a[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		cin >>c[i];
	}
	if(n<=20)dfs(1,0,0);
	else{
		if(ok()){
			ans=1;
	 		for(int i=1;i<=n;i++){
	 			ans=(ans*i)%mod;
			 }
		}
		else {
			cout << 0;
		}
	 } 
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
