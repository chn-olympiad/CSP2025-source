#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,m,a[5001],pre[5001];
int ans=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int l1,int l2,int f){
	if(x>n){
		return ;
	}
	if(l2>l1&&f>2){
		int p=1;
		for(int i=1;i<=n-x;i++){
			p=p*2%mod;
		}
		ans=(ans+p)%mod;
		return ;
	}
	dfs(x+1,l1,l2+a[x+1],f+1);
	dfs(x+1,l1,l2,f+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],0,1);
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
