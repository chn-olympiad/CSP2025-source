#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
ll t,n,ans,vis[MAXN];
bool flag=true;
struct people {
	ll a1,a2,a3,num;
} a[MAXN];
ll solve(){
	int ret=0,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1&&cnt1<n/2){
			ret+=a[i].a1,cnt1++;
		}
		if(vis[i]==2&&cnt2<n/2){
			ret+=a[i].a2,cnt2++;
		}
		if(vis[i]==3&&cnt3<n/2){
			ret+=a[i].a3,cnt3++;
		}
	}
	return ret;
}
void dfs(int step) {
	if(step>n) {
		ans=max(ans,solve());
		return;
	}
	if(!vis[step]) {
		vis[step]=1;
		dfs(step+1);
		vis[step]=0;
	}
	if(!vis[step]) {
		vis[step]=2;
		dfs(step+1);
		vis[step]=0;
	}
	if(!vis[step]) {
		vis[step]=3;
		dfs(step+1);
		vis[step]=0;
	}
	dfs(step+1);
}
bool cmp(people x,people y){
	return x.a1>y.a1;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		flag=true;
		memset(vis,0,sizeof(vis));
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0)flag=false;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
		}
		else{
			dfs(1);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1


