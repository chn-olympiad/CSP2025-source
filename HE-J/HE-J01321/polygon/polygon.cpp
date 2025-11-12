#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;//CCF rp++
const int mod=998244553;
long long n,a[505],vis[505];
long long ans,mx=-1,sum=0;
void dfs(int x,int y){
	if(y>=3&&x>n){
		if(mx*2<sum)ans=(ans+1)%mod;}
	if(x>n)return;
	dfs(x+1,y);
	int xx=mx; 
	mx=max(mx,a[x]);
	sum+=a[x];
	dfs(x+1,y+1);
	mx=xx;
	sum-=a[x];	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0);
	cout<<ans;
	return 0;
}
