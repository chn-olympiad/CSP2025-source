#include<iostream>
#include<set> 
using namespace std;
const int N=5005,Mod=998244353;
int n;
long long arr[N];
long long ans=0;
int vis[N];
set<long long> s;
void dfs(int x,long long ma,long long zh){
	if(ma*2<zh&&x>3){
		long long a=0;
		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<" ";
			a*=10;
			a+=(vis[i]+1);
		}
		int l=s.size();
		s.insert(a);
		if(s.size()!=l){
			ans++;
			ans=ans%Mod; 
		}
//		cout<<ma<<" "<<zh<<endl;
	}
	if(x>n){
		return;
	}
	vis[x]=1;
	dfs(x+1,max(ma,arr[x]),zh+arr[x]);
	vis[x]=0;
	dfs(x+1,ma,zh);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	vis[1]=1;
	dfs(2,arr[1],arr[1]);
	vis[1]=0;
	dfs(2,0,0);
	cout<<ans;
	return 0;
}
