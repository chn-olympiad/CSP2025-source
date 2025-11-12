#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],sum[N];
struct node{
	int l,r;
}b[N];
bool cmp(node u,node v){
	if(u.r!=v.r){
		return u.r<v.r;
	}
	return u.l<v.l;
}
map<ll,ll> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	sum[0]=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<sum[i-1]<<" "<<a[i]<<endl;
		sum[i]=sum[i-1]^a[i];
	}
	mp[k]=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(mp[sum[i]]){
			b[++cnt].l=mp[sum[i]];
			b[cnt].r=i;
		}
		
		
		mp[sum[i]^k]=i+1;
		
	}
	if(cnt==0){
		cout<<cnt;
		return 0;
	}
	ll ans=0;
	sort(b+1,b+1+cnt,cmp);
	//for(int i=1;i<=cnt;i++){
	//	cout<<b[i].l<<" "<<b[i].r<<endl;
//	}
	int now=b[1].r;
	ans=1;
	for(int i=2;i<=cnt;i++){
		if(b[i].l>now){
			
			ans++;
			now=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}