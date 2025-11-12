#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int a[N],n,pre[N],ans,b[N];
bool vis[N];
map<int,int> m,g;
void dfs(int x,int sum,int mx,int len,int last,int cnt){
	if(x>n){
		if(mx*2<sum&&len>=3&&(!m[cnt]||!g[sum])){
			ans++;
			for(int i=1;i<=len;i++) cout<<b[i]<<' ';
			cout<<"\n\n";
			m[cnt]=1;
			g[sum]=1;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[len+1]=a[i];
		for(int i=1;i<=len+1;i++) cout<<b[i]<<' ';
		cout<<'\n';
		dfs(x+1,sum+a[i],max(mx,a[i]),len+1,i,cnt+i);
		vis[i]=0;
	}
	dfs(x+1,sum,mx,len,last,cnt);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,0,0,0);
	cout<<ans;
	return 0;
} 


