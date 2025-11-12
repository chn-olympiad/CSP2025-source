#include <iostream>
using namespace std;

#define ll long long

ll n,a[5005],maxx=-1,ans;
bool vis[5005];

bool check(ll b[],ll x,ll cnt){
	ll ma=-1;
	for(int i=1;i<=cnt;i++) ma=max(ma,b[i]);
	if(x>ma*2) return 1;
	return 0;
}

void dfs(ll b[],ll sum,ll cnt,ll pre){
	if(cnt>=3&&check(b,sum,cnt)){
		//for(int i=1;i<=cnt;i++){
			//cout<<b[i]<<" ";
		//}
		//cout<<endl;
		ans++,ans%=998244353;
	}
	
	for(int i=pre+1;i<=n;i++){
		if(!vis[i]){
			b[cnt+1]=a[i];
			vis[i]=1;
			dfs(b,sum+a[i],cnt+1,i);
			vis[i]=0;
		}
	}
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ll b[5005];
	
	cin>>n;
	for(ll i=1;i<=n;i++) {cin>>a[i];maxx=max(maxx,a[i]);}
	
	if(maxx==1){
		ll x=n%998244353*(n-1)%998244353*(n-2)%998244353/2/3;
		cout<<x;
		return 0;
	}
	
	for(ll i=1;i<=n;i++){
		b[1]=a[i];
		vis[i]=1;
		dfs(b,a[i],1,i);
		vis[i]=0;
	}
	
	cout<<ans;
	
	return 0;	
}
