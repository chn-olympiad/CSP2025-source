#include<bits/stdc++.h>
using namespace std;
int n,a[5003],ans;
void dfs(int cnt,int sum,int mx,int sl){
	if(cnt==n+1){
		if(sl>2&&sum>mx*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(cnt+1,sum+a[cnt],max(mx,a[cnt]),sl+1);
	dfs(cnt+1,sum,mx,sl);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans/2%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
