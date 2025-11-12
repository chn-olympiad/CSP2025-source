#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+5;
const int mod=998244353;
LL n,a[N],sum,maxx=-0x3f3f3f3f;
int cnt1;
int ans;
void dfs(int x,LL k,LL s,LL m){
				if(x==n+1) return ;
				if(s>2*m) ans++;
				for(int i=x+1;i<=n;i++){
								dfs(i,k+1,s+a[i],max(m,a[i]));
				}
}
int main(){
				freopen("polygon.in","r",stdin);
				freopen("polygon.out","w",stdout);
				cin>>n;
				for(int i=1;i<=n;i++){
								cin>>a[i];
								sum+=a[i];
								maxx=max(maxx,a[i]);
								if(a[i]==1) cnt1++;
				}
				if(n==3){
								if(sum>2*maxx) cout<<1;
								else cout<<0;
								return 0;
				}
				if(cnt1==n){
								cout<<(n*(n-1)*(n-2)/6)%mod;
								return 0;
				}
				if(n<=20){
								dfs(0,0,0,0);
								cout<<ans;
								return 0;
				}
				return 0;
}
