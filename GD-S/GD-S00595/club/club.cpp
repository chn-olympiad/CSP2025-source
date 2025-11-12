#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,sum[10];
struct node{
	ll x,y,z,id,mx;
}a[100100];
ll op=0;
bool cmp(node a,node b){
	ll c,d,e,f;
	if(op==1)c=a.x,d=b.x,e=max(a.y,a.z),f=max(b.y,b.z);
	if(op==2)c=a.y,d=b.y,e=max(a.x,a.z),f=max(b.x,b.z);
	if(op==3)c=a.z,d=b.z,e=max(a.y,a.x),f=max(b.y,b.x);
	if(c!=a.mx)return 0;
	if(d!=b.mx)return 1;
	return c-e>d-f;
}
void solve(){
	sum[1]=sum[2]=sum[3]=op=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id=i;
		if(a[i].x>=a[i].y){
			if(a[i].x>=a[i].z)sum[1]++,a[i].mx=a[i].x;
			else sum[3]++,a[i].mx=a[i].z;
		}
		else{
			if(a[i].y>=a[i].z)sum[2]++,a[i].mx=a[i].y;
			else sum[3]++,a[i].mx=a[i].z;
		}
	}
	for(ll i=1;i<=3;i++){
		if(sum[i]>(n/2))op=i;
	}
	ll ans=0;
	if(op){
		sort(a+1,a+1+n,cmp);
		for(ll i=(n/2)+1;i<=n;i++){
			if(op==1)a[i].x=0;
			if(op==2)a[i].y=0;
			if(op==3)a[i].z=0;
		}
	}
	for(ll i=1;i<=n;i++){
		ans+=max(a[i].x,max(a[i].y,a[i].z));
	//	cout<<a[i].id<<" ";
	//	cout<<max(a[i].x,max(a[i].y,a[i].z))<<" ";
	}
//	for(ll i=1;i<=3;i++)cout<<sum[i]<<" ";
//	cout<<endl;
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;cin>>t;
	while(t--)solve();
	return 0;
}
