#include<bits/stdc++.h>
using namespace std;
int st[20];
int ans;
int n,m;
string s;
int c[20];
void dfs(int i,int sum){
	if(i>n){
		if(n-sum>=m)ans++;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(!st[j]){
			st[j]=1;
			if(sum>=c[j]||s[i-1]=='0')dfs(i+1,sum+1);
			else dfs(i+1,sum);
			st[j]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>s[i];
	dfs(1,0);
	cout<<ans;
}
