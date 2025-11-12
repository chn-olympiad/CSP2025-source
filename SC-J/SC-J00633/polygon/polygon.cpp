#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
void dfs(int x,int y,int z){
	int c=0;
	if(x>y*2 && z>=3){
		ans++;c=1;
	}
	if(z==n){
		return;
	}
	dfs(x+a[z+1],max(y,a[z+1]),z+1);
	if(c==1){
		ans--;
	}
		dfs(x,y,z+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans%998244353;
	return 0;
}
