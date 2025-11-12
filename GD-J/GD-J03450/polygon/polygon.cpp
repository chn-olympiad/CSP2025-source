#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010]={},ans=0;
void dfs(int edges,int max_,int sum,int now){
	if(edges==0){
		if(max_*2<sum)ans++;
		return;
	}
	if(now>n)return;
	dfs(edges,max_,sum,now+1);
	max_=max(a[now],max_);
	sum+=a[now];
	dfs(edges-1,max_,sum,now+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
