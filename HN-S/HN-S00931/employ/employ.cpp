#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
string s;
int n,m,an[1010],vis[1010],jc[505];
int  dfs(int x,int qs,int t){
	if(x>=m&&t>n) return 1;
	if(t>n) return 0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(an[i]<qs||s[t-1]=='1') sum+=dfs(x,qs+1,t+1);
		else sum+=dfs(x+1,qs,t+1);
		vis[i]=0;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+n+1);
	cout<<dfs(0,0,1)+1;
	return 0;
} 
