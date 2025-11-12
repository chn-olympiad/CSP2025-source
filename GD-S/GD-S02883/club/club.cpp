#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum[3],t;
struct nood{
	ll a,b,c;
	ll aa,bb,cc;
}e[1000000];
bool cmp(nood x,nood y){
	return x.aa>y.aa;
}
bool cmpp(nood x,nood y){
	return x.bb>y.bb;
}
bool cmppp(nood x,nood y){
	return x.cc>y.cc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin>>t;
	scanf("%lld",&t);
//	cout<<"?"<<t<<endl;
	while(t--){
		sum[1]=sum[0]=sum[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&e[i].a);
			scanf("%lld",&e[i].b);
			scanf("%lld",&e[i].c);
//			cin>>e[i].a>>e[i].b>>e[i].c;
			e[i].aa=e[i].a-max(e[i].b,e[i].c);
			e[i].bb=e[i].b-max(e[i].a,e[i].c);
			e[i].cc=e[i].c-max(e[i].a,e[i].b);
			if(e[i].aa>0){
				sum[0]++;
			}
			if(e[i].bb>0){
				sum[1]++;
			}
			if(e[i].cc>0){
				sum[2]++;
			}
		}
		ll ans=0;
		if(sum[0]<=n/2&&sum[1]<=n/2&&sum[2]<=n/2){
			//全部选最优的
			for(int i=1;i<=n;i++){
				ans+=max(e[i].a,max(e[i].b,e[i].c));
			} 
			cout<<ans<<endl;
//			return 0;
		}
		if(sum[0]>n/2){//a
			sort(e+1,e+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=e[i].a;
				}
				else{
					ans+=max(e[i].b,e[i].c);
				}
			}
			cout<<ans<<endl;
//			return 0;
		}
		if(sum[1]>n/2){//b
			sort(e+1,e+n+1,cmpp);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=e[i].b;
				}
				else{
					ans+=max(e[i].a,e[i].c);
				}
			}
			cout<<ans<<endl;
//			return 0;
		}
		if(sum[2]>n/2){//c
			sort(e+1,e+n+1,cmppp);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=e[i].c;
				}
				else{
					ans+=max(e[i].a,e[i].b);
				}
			}
			cout<<ans<<endl;
//			return 0;
		}
	}
}
