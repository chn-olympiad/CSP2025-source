#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;
int n,m;
string s;
ll ans;
int c[501];
bool f[501];
int up=0;
void dfs(int lv,int v){
	v%=MOD;
	if(lv==n+1&&v>=m){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			int _up=up;
			f[i]=1;
			if((c[i]>up?1:0)*(s[lv-1]=='0'?0:1)==0) up++;
			dfs(lv+1,v+(c[i]>up?1:0)*(s[lv-1]=='0'?0:1));
			f[i]=0;
			up=_up;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
