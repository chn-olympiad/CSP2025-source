#include<bits/stdc++.h>
using namespace std;
//暴力:DFS 
int n,a[5005];
long long ans;
long long mod=998244353;
void dfs(int pos,int sum,int num,int maxn,int tmp){
	if(sum>(2*maxn) && num>=3 && tmp==1){
		ans=(ans+1)%mod;
		//cout<<pos-1<<" "<<sum<<endl;
	}
	if(pos>n){	
		return;
	}
	dfs(pos+1,sum,num,maxn,0);
	dfs(pos+1,sum+a[pos],num+1,max(maxn,a[pos]),1);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}