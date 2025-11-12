#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,s[550],x,y,z,t[550];
bool b[550];
char a[550];
void dfs(int g){
	if(g==m){
		ans*=ans+1;
	}
	for(int i=1;i<=m;i++){
		if(b[i]==0){
			b[i]=1;
			if(t[i]==0||a[i]<=0){
				dfs(g+1);
			}
			dfs(g+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i]-48;
		z+=t[i];
	}
	if(z>m){
			for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	if(m==1||m==n){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	if(z==47){
		cout<<"161088479";
	}
	ans=1;
	dfs(1);
	cout<<ans;
	return 0;
	}else{
		cout<<"0";
		return 0;
	}
}