#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
char s[505];
bool b[505];
int dfs(int p,int fa){
	int re=0;
	b[p]=1;
	for(int i=1;i<=n;i++){
		if(b[p]!=0)continue;
		if(fa>=a[i])continue;
		if(s[p+1]=='1')re+=dfs(p+1,fa);
		else re+=dfs(p+1,fa+1);
		//cout<<re;
	}
	return re;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(1,0);
	return 0;
}
