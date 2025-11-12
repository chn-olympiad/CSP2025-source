#include<bits/stdc++.h>
using namespace std;
bool vis[222222];
long long n,a[222222],cg,ans,d[222222],sum,maxx;
void dfs(int x,int y,int c){
	if(x==y){
		sum=0;
		maxx=0;
		for(int i=1;i<=x;i++){
			sum+=d[i];
			maxx=max(maxx,d[i]);
		}
		maxx*=2;
		if(sum>maxx) ans++;
	}
	else{
		for(int i=c;i<=n;i++){
			if(!vis[i]){
				d[x+1]=a[i];
				vis[i]=1;
				dfs(x+1,y,i+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cg=max(cg,a[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,1);
	}
	cout<<ans;
	return 0;
}
