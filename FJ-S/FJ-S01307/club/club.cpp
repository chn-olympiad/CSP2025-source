#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =2E5+10;

struct NODE{
	ll val,i,j;
}b[N*3];
ll ans,n,t,fg[N],a[N][4],ton[20005];

void dfs(ll u,ll x,ll y,ll z,ll sum){
	ans = max(ans,sum);
	if(u>n) return;
	if(x<n/2) dfs(u+1,x+1,y,z,sum+a[u][1]);
	if(y<n/2) dfs(u+1,x,y+1,z,sum+a[u][2]);
	if(z<n/2) dfs(u+1,x,y,z+1,sum+a[u][3]);
}


int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;

		ll cnt=0;
		ll fa=1,fb=1,fc=1;
		
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			if(a[i][2]!=0) fa=0;
			cin>>a[i][3];
			if(a[i][3]!=0) fa=0,fb=0;
			if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][3]==a[i][2]) fc=0;
			
		}
		
		
		if(fa){
			ll tmp[N];
			for(int i=1;i<=n;i++) tmp[i] = a[i][1];
			sort(tmp+1,tmp+1+n);
			for(int i=1;i<=n/2;i++) ans+=tmp[i];
			cout<<ans<<endl;
			continue;
		}
		
	
		
		if(fa==0 and fb==0 and fc==0){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;	
		}
		
		
	} 
	
	
	return 0;
}
