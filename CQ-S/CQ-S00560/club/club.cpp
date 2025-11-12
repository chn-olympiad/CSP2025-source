#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,ans=0;
bool v[100010];
struct node{
	ll a1,a2,a3;
	ll a1_a2,q;
}a[100010];
void f(ll d,ll k1,ll k2,ll k3,ll cnt){
	if(d==n+1){
		ans=max(ans,cnt);
//		cout<<ans<<" ";
		return;
	}
	if(k1<n/2)f(d+1,k1+1,k2,k3,cnt+a[d].a1);
	if(k2<n/2)f(d+1,k1,k2+1,k3,cnt+a[d].a2);
	if(k3<n/2)f(d+1,k1,k2,k3+1,cnt+a[d].a3);
}
bool cmp1(node a,node b){
	return a.a1>b.a1;	
}
bool cmp2(node a,node b){
	return a.a1_a2>b.a1_a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		ll pa=0,pb=0;
		memset(v,0,sizeof(v));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2==0&&a[i].a3==0){
				pa++;
			}
			if(a[i].a3==0){
				pb++;
				if(a[i].a1>a[i].a2){
					a[i].a1_a2=a[i].a1-a[i].a2;
					a[i].q=1;
				}else{
					a[i].a1_a2=a[i].a2-a[i].a1;
					a[i].q=2;
				}
			}
		}
		if(pa==n){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}else if(pb==n){
			sort(a+1,a+n+1,cmp2);
			ll k1=0,k2=0;
			for(int i=1;i<=n;i++){
				if(k1==n/2){
					ans+=a[i].a2;
					k2++;
				}else if(k2==n/2){
					ans+=a[i].a1;
					k1++;
				}else if(a[i].q==1){
					ans+=a[i].a1;
					k1++;
				}else{
					ans+=a[i].a2;
					k2++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		f(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;	
}
