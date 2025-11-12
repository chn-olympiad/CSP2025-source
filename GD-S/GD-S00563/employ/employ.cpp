#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
const long long mod=998244353;
int c[505],tmp[15];
bool flag[15];
string s;
bool check(){
	int out=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') out++;
		else{
			if(out>=c[tmp[i]]) out++;
			else cnt++;
		}
	}
	return cnt>=m;
}
void dfs(int now){
	if(now>n){
		if(check()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		flag[i]=1;
		tmp[now]=i;
		dfs(now+1);
		flag[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=0;i<n;i++)
		if(s[i]!=s[i+1]){
			flag=0;
			break;
		}
//	if(s[1]=='1'&&flag==1){
		ans=1;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=mod;
		cout<<ans;
		return 0;
//	}
}
/*
11 2
11111111111
1 2 3 4 5 6 7 8 9 10 11
*/

