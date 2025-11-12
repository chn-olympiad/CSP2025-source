#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
int a[5005];
long long b[520][520];
void c(int ls){
for(int i=0;i<=ls+5;i++){
	b[i][0]=1;
	b[i][i]=1;
	}
	for(int i=2;i<=ls+3;i++){
		for(int j=1;j<=i-1;j++){
			b[i][j]=b[i-1][j]+b[i-1][j-1];
		}
	}
return ;
}
void dfs(int w,int maxn,long long h){
	if(w>n){
		if(h>maxn*2){
			ans++;
			ans%=998244353;
			}
			return ;
		}
	dfs(w+1,max(maxn,a[w]),h+a[w]);
	dfs(w+1,maxn,h);
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
bool k=1;
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]!=1)k=0;
	}
	if(k){
		c(n);
		for(int i=3;i<=n;i++){
			ans+=b[n][i];
			ans%=998244353;
			}
			cout<<ans;
			return 0;
		}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
