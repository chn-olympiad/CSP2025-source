#include <bits/stdc++.h>
using namespace std;
bool vis[200005];
long long cnt,n,m,ans,lv[200005],p=998244353;
string s;
long long c[2000005];
void dfs(int x,int sum){
	if(n-sum<m) return;
	if(x>n){
		ans+=((n-sum)>=m);
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(c[i]<=sum || s[x-1]=='0') dfs(x+1,sum+1);
		else dfs(x+1,sum);
		vis[i]=0;
	}
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);
    cout.tie(0); 
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);  
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i],cnt+=(c[i]=='1');
    if(n<=18){
    dfs(1,0);
    cout<<ans;
}
if(cnt==n){
	lv[1]=1;
	for(int i=2;i<=n;i++) lv[i]=lv[i-1]*i%p;
	cout<<lv[n];
}
cout<<0;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
3 2
101
1 1 2
*/
