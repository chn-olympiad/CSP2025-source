#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005][5];
ll n;
int t;
ll ans=0;
void dfs(ll k,ll t,ll n1,ll n2,ll n3){
	if(k>n){
		ans=max(ans,t);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && n1+1<=n/2) dfs(k+1,t+a[k][i],n1+1,n2,n3);
		if(i==2 && n2+1<=n/2) dfs(k+1,t+a[k][i],n1,n2+1,n3);
		if(i==3 && n3+1<=n/2) dfs(k+1,t+a[k][i],n1,n2,n3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(n<=10){
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else{
			ll ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		
	}
	return 0;
} 
