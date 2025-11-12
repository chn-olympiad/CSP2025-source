#include<bits/stdc++.h>
using namespace std;
int n,b=0,a[6000];
long long ans=0; 
void dfs(int x,int y,int z,int c){//边数，总和，当前边,最大边 
	if(b==x){
		if(y>2*a[c]) ans++;
		return;
	}
	if(z==n+1) return;
	dfs(x+1,y+a[z],z+1,z);
	dfs(x,y,z+1,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		b=i;
		dfs(0,0,1,0);
	}
	cout<<ans%998244353;
	return 0;
} 
