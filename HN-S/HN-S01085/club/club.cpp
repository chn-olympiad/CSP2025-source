#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,la,lb,lc;
ll ans=0;
ll a[100005],b[100005],c[100005];
ll f[100005];
ll x,y,z;
void dfs(ll x,ll s){
//	cout<<x<<' '<<s<<endl;
	if(x>=n){
		ans=max(ans,s);
		return ;
	}
	if(la<n/2){
		cout<<1<<endl;
		la++;
		dfs(x+1,s+a[x]);
		la--;
	}
	if(lb<n/2){
		cout<<2<<endl;
		lb++;
		dfs(x+1,s+b[x]);
		lb--;
	}
	if(z==0) return ;
	if(lc<n/2){
		cout<<3<<endl;
		lc++;
		dfs(x+1,s+c[x]);
		lc--;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			x+=a[i];
			y+=b[i];
			z+=c[i];
		}
		if(y==0&&z==0){
			cout<<x<<endl;
			continue;
		}
		dfs(0,0);
		cout<<ans<<endl;
		ans=0;
	}
	
}
