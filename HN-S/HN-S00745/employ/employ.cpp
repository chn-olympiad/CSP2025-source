#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],cnt,ans;
bool used[510];
string s;
void dfs(int now,int a[]){
	if(now>n){
		int die=0,sum=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=die||s[i-1]=='0') die++;
			else sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			a[now]=i;
			dfs(now+1,a);
			used[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int a[n+1]={};
	dfs(1,a);
	cout<<ans;
	return 0;
}
