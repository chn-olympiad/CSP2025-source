#include<bits/stdc++.h>
using namespace std;
int n,m,c[10005],vis[10005],ans;
char ch[10005];bool us[10005];
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(c[vis[i]]>cnt&&ch[i]=='1'){
				continue;
			}else cnt++;
		}
//		cout<<cnt<<'\n';
		if(cnt+m<=n){
			ans++;
//			for(int i=1;i<=n;++i)
//				cout<<vis[i]<<' ';
//			cout<<'\n';
		}
		return ;
	}
	for(int i=1;i<=n;++i)
		if(!us[i])
			us[i]=1,vis[x]=i,
			dfs(x+1),
			vis[x]=0,us[i]=0;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>ch[i];
	for(int i=1;i<=n;++i)
		cin>>c[i];
//	sort(c+1,c+n+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
} 
