#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,ans;
string x;
int s[N],c[N],f[N];
void dfs(int now,int day,int cnt){
//	cout<<now<<' ';
	if(day-cnt-1>=c[now]){
		if(day==n){
			if(cnt>=m) ans++;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				dfs(i,day+1,cnt);
				f[i]=0;
			}
		}
	}
	else if(s[day]==1){
		if(day==n){
			if(cnt+1>=m) ans++;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				dfs(i,day+1,cnt+1);
				f[i]=0;
			}
		}
	}
	else{
		if(day==n){
			if(cnt>=m) ans++;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				dfs(i,day+1,cnt);
				f[i]=0;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x;
	for(int i=0;i<x.length();i++){
		if(x[i]=='1') s[i]=1;
		else s[i]=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(i,1,0);
		f[i]=0;
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
}
