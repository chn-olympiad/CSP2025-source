#include<bits/stdc++.h>
#define ll long long
#define N 505
#define lg 25 
#define pii pair<ll,ll>
#define fi first
#define se second
#define mod 998244353
using namespace std;
ll n,m,c[N],f[N],vis[N],ans;
string s;
bool flag=true;
void dfs(ll x,string st){
//	cout<<x<<" "<<st<<endl; 
	if(x>n){
		ll byebye=0;
		for(int i=0;i<st.size();i++){
			if(c[(st[i]-'0')]<=byebye) byebye++;
			else if(s[i]=='0') byebye++;
		}
		if(n-byebye>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) vis[i]=1,dfs(x+1,st+char(i+'0')),vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	cin>>s;
	f[0]=1;
	for(int i=1;i<=n;i++){f[i]=(f[i-1]*i)%mod;}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,"");
	printf("%lld",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
