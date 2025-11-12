#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long ans,n;
void dfs(int x,int y,int z){
	if(x>=n){
		if(y*2<z){
			ans++;
		}
		return;
	}
	dfs(x+1,y+a[x],max(a[x],z));
	dfs(x+1,y,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxn=max(a[1],max(a[2],a[3]));
		int maxm=a[1]+a[2]+a[3];
		maxn*=2;
		if(maxn<maxm){
			cout<<1<<endl;
		}
	}else{
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
