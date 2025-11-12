#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+5,mod=998244353;
string s;
int n,m,a[N],p[N];
ll ans;
bool vis[N];
bool check(){
	int cnt=0,qz=0;
	for(int i=1;i<=n;++i){
		if(s[i-1]=='0'||qz>=a[p[i]])qz++;
		else if(s[i-1]=='1')cnt++;
	}
	if(cnt>=m)return true;
	return false;
}
void bfs(int cnt){
	if(cnt==n){
		if(check())ans++;
		if(ans==mod)ans=0;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=true;
			p[cnt+1]=i;
			bfs(cnt+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)cin>>a[i];
	bfs(0);
	cout<<ans;
	return 0;
}
