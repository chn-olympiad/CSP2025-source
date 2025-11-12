#include<bits/stdc++.h>
using namespace std;
const int A=998244353;
int n,a[5500],c[5005][5005],maxn;
int ans=0;
void DFS(int u,int maxn,int l,int num){
	if(u==n+1){
		if(l>2*maxn&&num>=3){
			ans++;
			ans%=A;
		}
		return ;
	}
	DFS(u+1,max(maxn,a[u]),l+a[u],num+1);
	DFS(u+1,maxn,l,num);
}
void di(){
	c[1][1]=1;
	for(int i=2;i<=5000;i++){
		c[i][1]=1;
		for(int j=2;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=A;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	if(n<=20){
		DFS(1,0,0,0);
	} else if(maxn==1){
		di();
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=A;
		}
	}
	cout<<ans;
	return 0;
}
