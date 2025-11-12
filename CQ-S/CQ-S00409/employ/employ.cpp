#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define mod
using namespace std;
const int N=20;
int n,m,ans,c[N];
bool mark[N];
char b[N];
void dfs(int d,int die,int cnt){
	if(d>n){
		if(cnt>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		mark[i]=1;
		if((b[d-1]=='0')||die>=c[i]) dfs(d+1,die+1,cnt);
		else dfs(d+1,die,cnt+1);
		mark[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*

*/

