#include<bits/stdc++.h>

#define In(x) freopen(x,"r",stdin)
#define Out(x) freopen(x,"w",stdout)

using namespace std;

typedef long long ll;

int n,m,ans;

const int N=505;

char s[N];

int c[N],id[N],vis[N];

struct Burf{
	inline void Dfs(int dep){
		if(dep>n){
			int cnt=0;
			for(int i=1;i<=n;i++) if(i-cnt<=c[id[i]]&&s[i]=='1') cnt++;
			ans+=(cnt>=m),ans%=998244353;
			return ;
		}
		for(int i=1;i<=n;i++) if(!vis[i]){
			vis[i]=1,id[dep]=i;
			Dfs(dep+1);
			vis[i]=0;
		}
	}
	inline void Solve(){
		Dfs(1);
		printf("%d",ans);
	}
};

struct A{
	inline void Solve(){
		
	}
};

struct N{
	inline void Solve(){
		for(int i=1;i<=n;i++) if(c[i]==0||s[i]=='0'){
			printf("0");
			return ;
		}
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ll)ans*i%998244353;
		printf("%d",ans);
	}
};

signed main()
{
	In("employ.in");Out("employ.out");
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10) (new Burf)->Solve();
	else if(n==m) (new N)->Solve();
	return 0;
}

