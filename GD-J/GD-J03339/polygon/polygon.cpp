#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
long long n,a[5010],ans=0;
bool vis[5010];
void dfs(long long lct,long long len,long long mx,long long sum){
	//cout<<lct<<' '<<len<<' '<<mx<<' '<<sum<<'\n';
	if(len>=3&&sum>mx*2)ans++;
	ans%=md;
	for(int i=lct+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		dfs(i,len+1,max(mx,a[i]),sum+a[i]);
		vis[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	//sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));	
		ans%=md;
		dfs(i,1,a[i],a[i]);
	}
	cout<<ans%md;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
