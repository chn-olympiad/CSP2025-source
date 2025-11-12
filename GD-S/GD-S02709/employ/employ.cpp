#include <bits/stdc++.h>
using namespace std;
char s[505];
int c[505],cnt[505];
int modp=998244353,p,n,m;
void dfs(int a,int num,int yes){
	if(cnt[a]){
		return;
	}
	if(num==n){
		if(yes>=m){
			p++;
			p%=modp;
		}
		return;
	}
	cnt[a]=1;
	if(s[a]=='1'){
		yes++;
	}
	for(int j=1;j<=n;j++){
		if(cnt[a]==0){
			dfs(j,num+1,yes);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	p=0;
	if(m==n){
		for(int i=1;i<=n;i++){
			cnt[i]++;
			p=max(p,c[i]);
		}
		for(int i=1;i<=n;i++){
			if(p<n||cnt[i]==0){
				cout<<0;
			}
		}
		cout<<1;
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<p;
}
