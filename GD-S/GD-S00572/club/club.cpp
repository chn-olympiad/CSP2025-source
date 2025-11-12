#include<bits/stdc++.h>
using namespace std;
int t,n;
const int maxn=1e5;
struct node{
	int a,b,c;
	bool operator < (const node &other){
		return a<other.a;
	}
}a[maxn];
long long ans;
void dfs(int dep,long long sum,int c0,int c1,int c2){
	if(dep>n){
		ans=max(ans,sum);
		return ;
	}
	if(c0<(n>>1)) dfs(dep+1,sum+a[dep].a,c0+1,c1,c2);
	if(c1<(n>>1)) dfs(dep+1,sum+a[dep].b,c0,c1+1,c2);
	if(c2<(n>>1)) dfs(dep+1,sum+a[dep].c,c0,c1,c2+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool f=1;
		for(int i=1;i<=n;++i){
			cin>>a[i].a>>a[i].b>>a[i].c;
			f=f&&(a[i].b==0&&a[i].c==0);
		}
		if(f){
			sort(a+1,a+n+1);
			for(int i=1;(i<<1)<=n;++i){
				ans+=a[i].a;
			}
			cout<<ans<<'\n';
		}
		else{
			dfs(1,0ll,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}

