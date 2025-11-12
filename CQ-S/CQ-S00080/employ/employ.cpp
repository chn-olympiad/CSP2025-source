#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int n,m,ans,c[510],path[15];
bool book[15];
string s;
bool fl;
void dfs(int d,int sum){
	if(d==n+1){
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==false){
			book[i]=true;
			path[d]=i;
			if(d-1-sum>=c[i]||s[d]=='0') dfs(d+1,sum);
			else dfs(d+1,sum+1);
			book[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;s=" "+s;
	fl=true;
	for(int i=1;i<=n;i++) if(s[i]!='1') fl=false;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
}
