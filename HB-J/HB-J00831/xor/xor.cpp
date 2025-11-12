#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N],ans=0;
void dfs(int x,int y,int cnt){
	if(abs(s[y]-s[x-1])==k){
		cnt++;
	} 
	if(y==n){
		ans=max(cnt,ans);
		return ;
	}
	for(int i=y+1;i<=n;i++){
		for(int j=0;j<=n-i;j++) dfs(i,i+j,cnt);
	} 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++) dfs(i,i+j,0);
	}
	cout<<ans;
	return 0;
}
