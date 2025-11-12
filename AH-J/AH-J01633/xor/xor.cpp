#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[100005],t,ans=1;

struct node{
	ll l,r;
}o;

vector<node> v;

bool cmp(node x,node y){return x.r<y.r;}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll l=1;l<=n;l++){
		for(ll r=l;r<=n;r++){
			ll x=a[l];
			for(ll i=l+1;i<=r;i++){
				x^=a[i];
			}if(x==k){
				o.l=l;
				o.r=r;
				v.push_back(o);
			}
		}
	}sort(v.begin(),v.end(),cmp);
	t=v[0].r;
	for(ll i=1;i<v.size();i++){
		if(v[i].l>t){
			ans++;
			t=v[i].r;
		}
	}cout<<ans;
	return 0;
}
