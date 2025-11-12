#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],cnt;
char c[505];
bool fx[505];
void dfs(int x,int lr){
	if(x>n){
		if(lr>=m)cnt++;
		return;
	}
	if(c[x]=='0'){
		for(int i=1;i<=n;i++){
			if(fx[i])continue;
			fx[i]=1;
			dfs(x+1,lr);
			fx[i]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(fx[i])continue;
			fx[i]=1;
			if(x-lr-1>=a[i])dfs(x+1,lr);
			else dfs(x+1,lr+1);
			fx[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<cnt;
	return 0;
}
//25+65-100+30=120-155
