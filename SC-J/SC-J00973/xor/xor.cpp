#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+6;
struct good{
	ll maxx;
	int l,r;
}t[N*4];
ll ls(ll x){return x*2;}
ll rs(ll x){return x*2+1;}
void pushup(ll x){
	t[x].maxx=max(t[ls(x)].maxx,t[rs(x)].maxx);
}
void add(ll x,ll l,ll a){
	if(t[x].l==t[x].r&&t[x].l==l){
		t[x].maxx=a;
		return;
	}
	ll mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		add(ls(x),l,a);
	else
		add(rs(x),l,a);
	pushup(x);
}
ll query(ll x,ll l,ll r){
	if(t[x].l>=l&&t[x].r<=r)
		return t[x].maxx;
	ll mid=(t[x].l+t[x].r)>>1;
	return max((l<=mid?query(ls(x),l,r):0ll),(r>=mid+1?query(rs(x),l,r):0ll));
}
void build(ll x,ll l,ll r){
	t[x].l=l,t[x].r=r,t[x].maxx=0;
	if(l==r)
		return;
	ll mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
}
ll a[N],dp[N],l[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	ll lmax=0,num=0;
	for(int r=1;r<=n;r++){
		num^=a[r];
		ll numm=num;
		for(int i=lmax;i<r;i++){
			if((numm^a[i])==k){
				lmax=i+1;
				l[r]=i+1;
				num=k;
			}
			numm^=a[i];
		}
	}
	ll maxx=0;
	for(int i=1;i<=n;i++){
		if(l[i]==0)
			continue;
		dp[i]=query(1,1,l[i]-1)+1;
		add(1,i,dp[i]);
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx<<"\n";
	return 0;
}