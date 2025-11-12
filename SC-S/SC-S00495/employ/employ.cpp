#include <bits/stdc++.h>
using namespace std;
int a[510],b[510],n,m,h;
int k[510],l[510],ans;
void check(){
	int p=0,t=0;
	for(int i=1;i<=h;i++){
		if(!k[i]||b[i]<=p) p++;
		else t++;
	}
	if(t>=m) ans++;
}
void dfs(int x){
	if(x>n){check();return;}
	for(int i=1;i<=n;i++){
		if(l[i]) continue;
		l[i]=1;
		b[++h]=a[i];
		dfs(x+1);
		b[h--]=0;
		l[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m>>s;
	bool f=true;
	for(int i=0;i<=n-1;i++){
		k[i+1]=s[i]-'0';
		if(k[i+1]==0) f=false;
	}
	if(m==n&&f){cout<<0;return 0;}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}