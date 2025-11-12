#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998224355;
int n,m,a[N],f[N],ans,vis[N],s[N];
string str;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[f[i]]>s[i]&&str[i]=='1') cnt++;
	}
	return cnt>=m;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			ans=(ans+1)%M;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			f[x]=i,vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	str=" "+str;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1];
		if(str[i]=='0') s[i]++;
	}
	dfs(1);
	cout<<ans;
	return 0;
}