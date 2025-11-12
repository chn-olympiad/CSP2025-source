#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define mn 200005
using namespace std;
int n,m,a[mn],to[mn],rt[mn],b[mn],ans,x,mo=998244353;
string s;
void dfs(int now){
	if(now==n+1){
		x=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') x++;
			else if(x>=a[b[i]]) x++;
		}
		if(n-x>=m) ans++;
		if(ans>mo) ans%=mo;
		return;
	}
	int f=0;
	while(to[f]<=n){
		f=to[f];
		to[rt[f]]=to[f];
		rt[to[f]]=rt[f];
		b[now]=f;
		dfs(now+1);
		to[rt[f]]=f;
		rt[to[f]]=f;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n;i++) to[i]=i+1;
	for(int i=1;i<=n+1;i++) rt[i]=i-1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
