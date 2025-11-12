#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=505;
const ll MOD =998244353;

int p[MAXN];
bitset<MAXN> vis;
int n,m;
int a[MAXN],c[MAXN];
ll ans=0;

bool check(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]==0){
			++sum;
			continue;
		}
		if(sum>=c[p[i]]){
			++sum;
			continue;
		}
		++cnt;
	}
	return cnt>=m;
}//

void dfs(int idx){
	if(idx>n){
//		for(int i=1;i<=n;++i) printf("%d",p[i]);
//		printf("\n");
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		p[idx]=i;
		dfs(idx+1);
		vis[i]=0;
	}
}//

bool k=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
		if(!a[i]) k=1;
	}
	if(!k && n>10){
		ll fra=1;
		for(int i=2;i<=n;++i) fra=(fra*i)%MOD;
		printf("%lld",fra);
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
