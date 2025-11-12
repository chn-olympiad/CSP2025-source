#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m; 
const int N=550;
int c[N];
bool vis[N];
string s;
int ans;
void find(int u,int need,int dead,int day){
	if(vis[u]) return ;
	vis[u]=true;
	if(s[day-1]=='1'&&dead<c[u]) need++;
	else dead++;
	if(day==n&&need>=m){
		ans++;
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		find(i,need,dead,day+1);
	}
	vis[u]=false;
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		find(i,0,0,1);
	}
	printf("%lld",ans%998244353);
	return 0;
}
