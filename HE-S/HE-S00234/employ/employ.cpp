#include<bits/stdc++.h>
using namespace std;
char s[10001];
int n,m,ans=0,z[1001],c[1001];
void dfs(int I){
	if(I==n+1){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')tot++;
			else if(tot>=c[z[i]])tot++;
		}
		if(n-tot>=m)ans++;
		return ;
	}
	for(int j=I;j<=n;j++){
		swap(z[I],z[j]);
		dfs(I+1);
		swap(z[I],z[j]);
	}
}
int dp[1001][1001][2];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;i++)z[i]=i;
		dfs(1);
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		for(int w=1;w<(1<<n);w++){
//			if
//		}
//	} 
	return 0;
}
