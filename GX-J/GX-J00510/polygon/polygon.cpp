#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,ans=0;
void dfs(int x,int y,int z){
	if(z==0){
		if(y>2*a[x]){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=x+1;i<=n-z+1;i++){
		dfs(i,y+a[i],z-1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,0,i);
	}
	cout<<ans;
	return 0;
}
