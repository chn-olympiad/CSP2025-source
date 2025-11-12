#include<iostream>
using namespace std;
long long n,sum,a[5010],vis[5010];
unsigned __int128 ans;
void dfs(long long now,long long cnt,long long sum,long long mx){
	if(now>n){
		if(cnt<3){
			return;
		}
		if(sum<=mx*2){
			return;
		}
		ans+=1;
		ans%=998244353;
		return;
	}
	vis[now]=1;
	dfs(now+1,cnt+1,sum+a[now],max(mx,a[now]));
	vis[now]=0;
	dfs(now+1,cnt,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	long long an=ans;
	cout<<an;
	return 0;
}
