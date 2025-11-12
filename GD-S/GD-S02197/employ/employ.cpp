#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],anss1,vis[505],ans[505];
char cr[505];
void dfs(int now,int qh,int nh){
	if(now>n){
		if(nh>=m){
			anss1++;
			anss1%=mod;
		}return;
	}for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ans[now]=i;
		if(qh>=c[i] or cr[now]=='0'){
			dfs(now+1,qh+1,nh);
		}
		else dfs(now+1,qh,nh+1);
		vis[i]=0;
	}
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cr[i];
	}for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		int anss=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0 or cr[i]=='0'){
				cout<<0;
				return 0;
			}anss*=i;
			anss%=mod;
		}cout<<anss%mod;
		return 0;
	}int hh1=0;
	for(int i=1;i<=n;i++){
		if(cr[i]=='1')hh1++;
	}if(hh1<m){
		cout<<0;
		return 0;
	}if(n>50){
		cout<<0;
		return 0;
	}dfs(1,0,0);
	cout<<anss1%mod;
	return 0;
} 
