#include<iostream>
#include<algorithm>
using namespace std;
const int N=5002,MOD=998224353;
int n;
int a[N];
int f[N];
int ans;
void dfs(int dep,int cnt,int sum,int gre,int ces){
	if(dep>ces&&cnt>=2&&sum>gre){
		ans++;
		ans%=MOD;
		return ;
	}
	if(dep>ces)return ;
	dfs(dep+1,cnt,sum,gre,ces);
	dfs(dep+1,cnt+1,sum+a[dep],gre,ces);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(1,0,0,a[i],i-1);
	}
	cout<<ans;
}
