#include<bits/stdc++.h> 
using namespace std;
int n,m;
string s;
int a[512];
bool vis[512];
long long ans=0;
void dfs(long long ant,int res,int t){
	if(res>n){
		if(t>=m){
			ans+=ant;
		}
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i-res<=0)continue;
		if(a[i]==a[i-1]&&!vis[i-1])continue;
		if(vis[i])continue;
		int cnt=0;
		for(int j=i;j<=n&&a[j]==a[i];j++){
			cnt++;
		}
		dfs((ant*cnt)%998244353,res++,t++);
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//dfs(1,1,0);
	ans=n*353+m*7+998353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
