#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
int a[5005]={};
bool vis[5005]={};
bool cmp(int x,int y){
	return x>y;
}
void dfs(int now,int num,int best,int how,bool can){
	if(how>=3&&can&&num>2*best){
		ans++;
	}
	if(now>n)return;
	dfs(now+1,num,best,how,0);
	dfs(now+1,num+a[now],max(best,a[now]),how+1,1);
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	dfs(0,0,0,0,0);
	cout<<ans/2;
	return 0;
} 
