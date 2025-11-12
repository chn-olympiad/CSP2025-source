#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500000+10],sd[500000+10],len=0,sum[500000+10];
struct node{
	ll val,l,r;
}ans[5000000+10];
bool cmp(node n1,node n2){
	if(n1.val==n2.val){
		if(n1.l==n2.l) return n1.r<n2.r;
		else return n1.l<n2.l;
	}
	return n1.val<n2.val;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans[++len].val=j-i+1;
				ans[len].l=i;
				ans[len].r=j;
			}
		}
	}
	sort(ans+1,ans+len+1,cmp);
	ll anss=0;
	for(ll i=1;i<=n;i++){
		ll f=0;
		for(ll j=ans[i].l;j<=ans[i].r;j++){
			if(sd[j]==1){
				f=1;
				break;
			}
		}
		if(f==0){
			for(ll j=ans[i].l;j<=ans[i].r;j++) sd[j]=1;
			anss++;
		}
	}
	cout<<anss;
	return 0;
}