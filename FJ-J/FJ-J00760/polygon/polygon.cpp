#include<bits/stdc++.h>
using namespace std;
int n,a[5002],ans,N=998244353,f;
void dfs(int x,int y,int z){
	for(int i=x+1;i<=n;i++){
		if(a[i]<z&&y>2)ans=(ans+1)%N;
		dfs(i,y+1,z+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],f=max(f,a[i]);
	if(f==1){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*2%N;
		ans=(ans-n+N)%N,ans=(ans-n*(n-1)/2-1+N)%N;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
