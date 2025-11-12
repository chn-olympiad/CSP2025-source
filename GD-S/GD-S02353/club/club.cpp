#include<bits/stdc++.h>
using ll=long long;
struct node{
	int a,b,c;
};
bool cmp(node x,node y){
	return x.a+x.b+x.c>y.a+y.b+y.c;
}
ll vis[10];
node d[100005];
ll mp[100005][5];
void solve(){
	std::memset(vis,0,sizeof(vis));
	ll n;
	std::cin>>n;
	if(n==2){
		std::memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				std::cin>>mp[i][j];
			}
		}
		ll maxn=-1;
		ll ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				int byd=mp[2][j];
				maxn=std::max(maxn,mp[1][i]+byd);
			}
		}
		std::cout<<maxn<<std::endl;
	}else {
		for(int i=1;i<=n;i++){
			std::cin>>d[i].a>>d[i].b>>d[i].c;
		}
		std::sort(d+1,d+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int a=d[i].a;
			int b=d[i].b;
			int c=d[i].c;
			if(a>=b and a>=c and vis[1]<n/2){
				vis[1]++;
				ans+=a;
			}else if(b>=a and b>=c and vis[2]<n/2){
				vis[2]++;
				ans+=b;
			}else {
				vis[3]++;
				ans+=c;
			}
		}
		std::cout<<ans<<std::endl; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	std::cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
