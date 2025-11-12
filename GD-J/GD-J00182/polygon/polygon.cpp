#include<iostream>
using namespace std;
int a[5005],n,ans=0;
void dfs(int x,int s,int cnt,int mx){
	if(x==n+1){
		if(cnt>2 && s>mx*2) ans=(ans+1)%998244353;
		return;
	}
	dfs(x+1,s,cnt,mx);//不选择当前小木棍 
	dfs(x+1,s+a[x],cnt+1,max(mx,a[x]));//选择当前小木棍 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
