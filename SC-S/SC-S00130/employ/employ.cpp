#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll N=510,mod=998244353;
ll n,m,ans,a[N],c[N];
bool f=true,used[N];
char s[N];
ll Pow(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1,a=a*a%mod;
	}
	return res;
}
void dfs(ll st,ll fl){
	if(st==n+1){
		if(n-fl==m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			a[st]=i;
			if(fl>=c[i]||s[st]=='0')dfs(st+1,fl+1);
			else dfs(st+1,fl);
			used[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s+1;
    for(int i=1;i<=n;i++)if(s[i]!='1')f=false;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(!f)dfs(1,0);
	else ans=Pow(2,n,mod)%mod;
	cout<<ans;
	return 0;
}