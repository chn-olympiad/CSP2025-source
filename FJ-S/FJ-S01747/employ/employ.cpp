#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long ans;
int a[600],c[600],b[600];
int v[600];
void dfs(int pos,int n){
	if(pos>n){
		long long t=0;
		for(int i=1;i<=n;i++){
			if(c[b[i]]>=i-1&&a[i]==1)t++;
		}
		if(m<=t){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			b[pos]=i;
			v[i]=1;
			dfs(pos+1,n);
			v[i]=0;
		}
	}
}
void dfs2(int pos,int n){
	if(pos>n){
		long long t=0;
		for(int i=1;i<=n;i++){
			if(c[b[i]]>=i-1)t++;
		}
		if(m<=t){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			b[pos]=i;
			v[i]=1;
			dfs(pos+1,n);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=true;
	for(int i=0;i<n;i++){
		cin>>c[i+1];
		a[i+1]=s[i]-'0';
		if(s[i]!=0)f=false;
	}
	if(f){
		dfs2(1,n);
		return 0;
	}
	dfs(1,n);
	cout<<ans;
	
	return 0;
}

