#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,a[N],f[N],cnt,len,R;
bool vis;
struct Node{
	ll l,r;
}b[N];
bool cmp(const Node &x,const Node &y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		if(a[i]!=1) vis=false;
	}
	if(!k&&vis){cout<<n/2;return 0;}
	for(ll r=1;r<=n;r++){
		for(ll l=1;l<=r;l++){
			if((f[r]^f[l-1])==k){b[++len].l=l;b[len].r=r;}
		}
	}
	sort(b+1,b+len+1,cmp);
	for(ll i=1;i<=len;i++){
		if(b[i].l>R){
			R=b[i].r;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
