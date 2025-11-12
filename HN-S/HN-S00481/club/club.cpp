#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,a[3][100005];
ll n,T,r[3];
ll jl[100005];
struct node{
	ll a,b;
}f[100005];
void dfs(ll u,ll x){
	if(x==n){
		if(u>ans&&r[0]<=n/2&&r[1]<=n/2&&r[2]<=n/2){
			ans=u;
		}
		return ;
	}
	for(ll i=0;i<3;i++){
		r[i]++;
		dfs(u+a[i][x],x+1);
		r[i]--;
	}
	return ;
}
bool g(node a,node b){
	return a.a<b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool pd=0;
		for(ll i=0;i<n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(a[0][i]!=0 or a[2][i]!=0){
				pd=1;
			}
		}	
		if(n<=30)r[3]={0},dfs(0,0);
		else{
			for(ll i=0;i<n;i++){
				f[i].a=a[0][i]-a[i][1];
				f[i].b=i;
			}
			sort(f,f+n,g);
			for(ll i=0;i<n/2;i++){
				jl[f[i].b]=1;
			}
			for(ll i=0;i<n;i++){
				ans+=a[jl[i]][i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
