#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+14;
struct node{
	int x,y;
};
ll n,k;
ll a[N],sum[N],l_c=-1,ans=1;
node cnt[N];
void add(ll s){
	ll p=a[s],q=sum[s-1];
	ll l_x,l_y;
	l_x=l_y=-1;
	int x[N],y[N],z[N];
	while(p>0){
		x[++l_x]=p%2;
		p/=2;
	}
	if(q==0) sum[s]=p;
	else{
		while(q>0){
			y[++l_y]=q%2;
			q/=2;
		}
		ll l=max(l_x,l_y);
		for(ll i=l;i>=0;i--){
			if(x[i]==y[i]) z[i]=0;
			else z[i]=1;
		}
		for(ll i=0;i<=l;i++){
			sum[s]+=pow(2,i)*z[i];
		}
	}
	return;
}
ll cmp(node e,node f){
	return e.y<f.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		add(i);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<n;j++){
			if(sum[j]-sum[i]==k){
				cnt[++l_c].x=i;
				cnt[l_c].y=j;
			}
		}
	}
	sort(cnt,cnt+l_c+1,cmp);
	for(ll i=1;i<=n;i++){
		if(cnt[i].y<cnt[i].x) ans++;
	}
	cout<<ans;
	return 0;
}
