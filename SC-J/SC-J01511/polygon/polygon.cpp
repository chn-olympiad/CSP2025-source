#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long c(int a,int b){
	if(a==b){
		return 1;
	}
	long long ans=1;
	for(int i=1;i<=a;i++){
		ans*=i;
	}
	long long ans2=1;
	for(int i=1;i<=b;i++){
		ans2*=i;
	}
	return ans/(ans2*(a-b))%mod;
}
int n;
int a[1001000];
bool vis[100100];
bool h[110][100100];
struct st{
	int x,y;
}cnt[8001000];
int idx;
void dfs(int sum,int ma,int gs,int x){
	if(gs>n||vis[x]){
		return ;
	}
	if(sum!=0&&gs>=3){
		if(h[ma][sum]==0){
			h[ma][sum]=1;
			cnt[++idx]={sum,ma};
		}
	}
	sum+=a[x],ma=max(ma,a[x]);
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(sum,ma,gs+1,i);
		}
	}
	vis[x]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=c(n,i);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	int ans=idx;
	for(int i=1;i<=idx;i++){
		if(cnt[i].x<cnt[i].y*2){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}