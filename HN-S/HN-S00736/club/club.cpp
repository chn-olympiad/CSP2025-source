#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
#define ll long long
struct node{
	ll x,y,z;
}a[N];
ll n,t,z,ans,T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		z=n/2;
		if(n==2){
			cin>>a[1].x>>a[1].y>>a[1].z;
			cin>>a[2].x>>a[2].y>>a[2].z;
			ll q=a[1].x+a[2].y;
			ll w=a[1].x+a[2].z;
			ll e=a[1].y+a[2].x;
			ll r=a[1].y+a[2].z;
			ll t=a[1].z+a[2].x;
			ll y=a[1].z+a[2].y;
			ans=max(max(max(q,w),max(e,r)),max(t,y));
			cout<<ans;
			break;
		}
		
	}
	
	
	return 0;
}
