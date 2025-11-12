#include<bits/stdc++.h>
#define N 510
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,c[N];
bool flagA=true;
string s;
namespace subtask1{
	int p[N],ans;
	bool check(){
		int failed=0;
		for(int i=0;i<n;++i){
			if(s[i]=='0') { ++failed; continue; }
			if(c[p[i+1]]<=failed) { ++failed; continue; }
		}
		return n-failed>=m;
	}
	void solve(){
		for(int i=1;i<=n;++i) p[i]=i;
		do{
			ans+=check();
		}while(next_permutation(p+1,p+1+n));
		printf("%d\n",ans);
	}
}
namespace subtaskA{
	void solve(){
		ll ans=1;
		for(int i=1;i<=n;++i) ans=ans*i%mod;
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m); getchar(); cin>>s;
	for(int i=0;i<n;++i) flagA&=(s[i]=='1');
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	if(n<=10) subtask1::solve();
	else if(m==n){
		int flag=false; ll ans=1;
		for(int i=1;i<=n;++i) flag|=(c[i]==0), ans=ans*i%mod;
		if(flag || !flagA) puts("0");
		else printf("%lld\n",ans);
	}else if(flagA) subtaskA::solve();
	else subtask1::solve();
	return 0;
}