#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m;
string s;
ll a[505];
bool f[505];
ll cnt;
void dfs(int x,int d,int p){
	if(p==m){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		if(s[x]=='0'||d>=a[i])dfs(x+1,d+1,p);
		else dfs(x+1,d,p+1);
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(0,0,0);
	printf("%lld",cnt%mod);
	return 0;
}
