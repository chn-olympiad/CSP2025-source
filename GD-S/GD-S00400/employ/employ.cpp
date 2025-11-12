#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,m,ans=0;
string s;
bool vis[1145141];
int b[1141541];
int c[1145141];
bool flag1=true;
vector<int>g;
int win,lo;
void dfs(int dep){
	if(dep>n){
		g.clear();
		win=0,lo=0;
		for(int i=1;i<=n;i++){
			g.push_back(c[b[i]]);
		}
		for(int i=0;i<g.size();i++){
			if(lo>=g[i]){
				lo++;
				continue;
			}
			if(s[i+1]=='1')
			win++;
			if(s[i+1]=='0')
			lo++;
		}
		if(win>=m){
			ans++;
			ans%=M;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[i]=dep;
			vis[i]=true;
			dfs(dep+1);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(NULL));
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			flag1=false;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(!flag1&&n<=10){
	dfs(1);
	cout<<ans;
	return 0;
	}
	cout<<0;
//	next_premuation(c,c+n);
	return 0;
	
}
/* 
3 2
1 1 2
*/
//10
