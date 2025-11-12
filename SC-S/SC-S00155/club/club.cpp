#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N=1e5+5;
ll n,b[N],ans=-1e18,t;
struct node{
	ll x,y,z;
}a[N];
map<ll,ll> mpx,mpy,mpz;
bool cmp(node l,node r){
	return l.x>r.x;
}
bool cmp1(node l,node r){
	if(l.x==r.x){
		return l.y<r.y;
	}else{
		return l.x>r.x;
	}
}
bool cmp2(node l,node r){
	if(l.y==r.y){
		return l.x<r.x;
	}else{
		return l.y>r.y;
	}
}
void dfs(ll k,ll x,ll y,ll z){
	if(k==n+1){
		ll cnt=0;
		if(x>n/2||y>n/2||z>n/2){
			return;
		}
		for(ll i=1;i<=n;i++){
			cnt+=b[i];
		}
		ans=max(ans,cnt);
		return;
	}
	if(x+1<=n/2){
		b[k]=a[k].x;
		dfs(k+1,x+1,y,z);
	}
	if(y+1<=n/2){
		b[k]=a[k].y;
		dfs(k+1,x,y+1,z);
	}
	if(z+1<=n/2){
		b[k]=a[k].z;
		dfs(k+1,x,y,z+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1e18;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			mpx[a[i].x]++;
			mpy[a[i].y]++;
			mpz[a[i].z]++;
		}
		if(n<=10){
			dfs(1,0,0,0);
			cout<<ans<<endl;
			continue;
		}else if(mpy[0]==n&&mpz[0]==n){
			ans=0;
			sort(a+1,a+n+1,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}else if(mpz[0]==n){
			ans=0;
			ll ans2=0;
			sort(a+1,a+n+1,cmp1);
//			for(ll i=1;i<=n;i++){
//				cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//			}
			for(ll i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			for(ll i=n/2+1;i<=n;i++){
				ans+=a[i].y;
			}
			sort(a+1,a+n+1,cmp2);
//			for(ll i=1;i<=n;i++){
//				cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//			}
			for(ll i=1;i<=n/2;i++){
				ans2+=a[i].y;
			}
			for(ll i=n/2+1;i<=n;i++){
				ans2+=a[i].x;
			}
			cout<<max(ans,ans2)<<endl;
			continue;
		}else{
			ans=0;
			for(ll i=1;i<=n/3;i++){
				ans+=a[i].x;
			}
			for(ll i=n/3+1;i<=n/3*2;i++){
				ans+=a[i].y;
			}
			for(ll i=n/3*2+1;i<=n;i++){
				ans+=a[i].z;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
 
1
4
2 2 0
2 1 0
3 1 0
3 2 0
 
*/