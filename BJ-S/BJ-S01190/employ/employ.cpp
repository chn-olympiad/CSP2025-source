#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353;
typedef long long ll;
int c[N],n,m;
string s;
namespace bf{
	int a[N],vis[N]={0},ans;
	void dfs(int x){
		if(x>n){
			int sum=0,tot=0;
			for(int i=1;i<=n;i++){
			//cout<<a[i]<<' ';
				if(sum>=a[i] || s[i]=='0')sum++;
				else tot++;
			}
			//cout<<endl<<tot<<' '<<sum<<endl;
			ans+=(tot>=m);
		}
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vis[i]=1;
			a[x]=c[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
	void main(){
		dfs(1);
		printf("%d",ans);
	}
};
namespace gg{
	void main(){
		int f=1;
		for(int i=1;i<=n;i++)if(s[i]==0 || c[i]=='0')f=0;
		ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		printf("%lld",ans*f);
	}
	
}
namespace A{
	void main(){
		int tt=0;
		for(int i=1;i<=n;i++)if(c[i]==0)tt++;
		if(n-tt<m)printf("-1");
		else{
			ll ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			printf("%lld",ans);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(m!=n)bf::main();
	else if(m==n)gg::main();
	return 0;
}