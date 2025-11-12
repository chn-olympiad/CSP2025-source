#include<bits/stdc++.h>
using namespace std;
int n,sd[101],td[101],box[101],box2[101],maxn,vis[101];
void bd(int x){
	int t=0,s=0;
	for(int i=1;i<=x;i++){
		t+=box2[i];
		s+=box[i];
	}
	if(s==t) maxn=max(s+t,maxn);
}
void dfs(int x,int y){
	if(x==y+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			box[x]=sd[i];
			box2[x]=td[i];
			bd(x);
			vis[i]=1;
			dfs(x+1,y);
			vis[i]=0;
		}
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sd[i]>>td[i];
	dfs(1,n);
	cout<<maxn;
	return 0;
}
