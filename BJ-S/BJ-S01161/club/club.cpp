#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=1e5+5;
struct node{
	ll x,y,z;
}a[N];
ll n,Max=-1e18;
void dfs(ll k,ll sum,ll s1,ll s2,ll s3){
	if(k==n+1){
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			Max=max(Max,sum);
		}
		return;
	}
	dfs(k+1,sum+a[k].x,s1+1,s2,s3);
	dfs(k+1,sum+a[k].y,s1,s2+1,s3);
	dfs(k+1,sum+a[k].z,s1,s2,s3+1);
}
bool cmp(node x,node y){
	retunr x.x<y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<Max<<"\n";
		}
		else{
			sort(a+1,a+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			for(ll i=n/2+1;i<=n;i++){
				sum+=a[i].y;
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}