#include<bits/stdc++.h>
using namespace std;

const int _=1e5+5,mod=998244353;

int n,m,tot=1,ans;
int a[_],b[_],now[_],vis[_];
char ch;

void check(){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		int j=now[i];
		if(a[i]==0||b[j]<=cnt)++cnt;
		else ++res;
	}
	if(res>=m)++ans;
}
void dfs(int x){
	if(x>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		now[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='1')a[i]=1;
		tot&=a[i];
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	dfs(1);
	cout<<ans;
	return 0;
}
