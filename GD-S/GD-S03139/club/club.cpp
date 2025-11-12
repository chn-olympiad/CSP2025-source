#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1e5+5;
ll t,n,ans;

struct g{
	ll x,y,z;
}a[maxn];

void dfs(ll j,ll sum,ll c1,ll c2,ll c3){
	if(j==n+1){
		ans=max(ans,sum);
		return ;
	}
	
	for(int i=1;i<=3;i++){
		if(i==1&&c1+1>n/2) continue;
		if(i==2&&c2+1>n/2) continue;
		if(i==3&&c3+1>n/2) continue;
		
		if(i==1) dfs(j+1,sum+a[j].x,c1+1,c2,c3);
		else if(i==2) dfs(j+1,sum+a[j].y,c1,c2+1,c3);
		else dfs(j+1,sum+a[j].z,c1,c2,c3+1);
	}
}

bool cmp(g x,g y){
	return x.x>y.x;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	cin>>t;
	while(t--){
		cin>>n;
		
		ll f=0;
		for(int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y==a[i].z&&a[i].y==0)f++;
		}
		
		if(f==n){
			int x=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				x+=a[i].x;
			}
			cout<<x<<endl;
			continue;
		}
		
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
