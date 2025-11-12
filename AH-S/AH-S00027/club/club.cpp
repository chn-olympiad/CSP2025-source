#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	ll a1,a2,a3;
}a[100005];
bool cmpa(const st &x,const st &y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T,n;
	cin>>T;
	while(T--){
		bool fa=1,fb=1;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0)fa=0;
			if(a[i].a3!=0)fb=0;
		}
		if(n==2){
			ll s1=a[1].a1+a[2].a2,s2=a[1].a1+a[2].a3,s3=a[1].a2+a[2].a1;
			ll s4=a[1].a2+a[2].a3,s5=a[1].a3+a[2].a1,s6=a[1].a3+a[2].a2;
			ll maxn=max(max(max(s1,s2),s3),max(max(s4,s5),s6));
			cout<<maxn;
			return 0;
		}
		if(fa==1){
			ll ansa=0;
			sort(a+1,a+1+n,cmpa);
			for(ll i=1;i<=n/2;i++)ansa+=a[i].a1;
			cout<<ansa;
			return 0;
		}
	}
	return 0;
}
