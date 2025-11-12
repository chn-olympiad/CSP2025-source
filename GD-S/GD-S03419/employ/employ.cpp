#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
long long n,m,b[N],a[N],p=998244353,ans,ans1;
string s;
void dfs(int x,int t){
	if(x>=n){
		if(t>=m) ans=(ans+1)%p;
		return;
	}
	for(int i=0;i<n;i++){
		if(b[i]) continue;
		if(s[x]=='1'&&a[i]>x-t){
			b[i]=1;
			dfs(x+1,t+1);
			b[i]=0;
		}
		else{
			b[i]=1;
			dfs(x+1,t);
			b[i]=0;
		}
	}
}
void dfs1(int x){
	if(x>=n){
		return;
	}
	for(int i=0;i<n;i++){
		if(b[i]) continue;
		if(s[x]=='1'&&a[i]>x){
			for(int i=1;i<=n-x-1;i++) ans1=ans1*(n-x-1)%p;
		}
		else{
			b[i]=1;
			dfs1(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		dfs1(0);
		cout<<ans1;
	}
	else{
		dfs(0,0);
		cout<<ans;
	}
	return 0;
}
