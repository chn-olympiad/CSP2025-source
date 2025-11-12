#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int cnt,int sum,int ma,int b){
	if(cnt==n+1){
		return ;
	}
	if(sum>2*ma&&b){
		ans++;
		ans%=998244353;
	}
	dfs(cnt+1,sum+a[cnt+1],a[cnt+1],1);
	dfs(cnt+1,sum,ma,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
