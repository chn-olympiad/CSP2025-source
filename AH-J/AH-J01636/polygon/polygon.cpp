#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010],cnt;
void dfs(int k,int sum,int m,int x,int f){
	if(k>=3&&sum>m*2&&f==1){
		cnt++;
		cnt%=998244353;
	}
	if(x==n)return;
	if(vis[x]==0){
		vis[x]=1;
		dfs(k+1,sum+a[x],a[x],x+1,1);
		vis[x]=0;
	}
	dfs(k,sum,m,x+1,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f==1){
		cout<<((n-1)*(n-2)/2)%998244353;
	}
	else{
		sort(a,a+n);
		dfs(0,0,0,0,0);
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
