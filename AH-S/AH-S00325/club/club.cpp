#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ST{
	ll a,b,c;
	ll max1,max2,max3;
	ll mop1,mop2,mop3;
}p[110000];
bool cmp(const ST &x,const ST &y){
	if(x.max1-x.max2!=y.max1-y.max2) return x.max1-x.max2>y.max1-y.max2;
	else{
		if(x.max2-x.max3!=y.max2-y.max3) return x.max2-x.max3>y.max2-y.max3;
		else return x.max1>y.max1;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		ll n,sum=0;
		ll d[4]={0,0,0,0};
		cin>>n;
		for(ll i=1;i<=n;i++){
			scanf("%lld %lld %lld",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
				p[i].max1=p[i].a;
				p[i].mop1=1;
				if(p[i].b>p[i].c){
					p[i].max2=p[i].b;
					p[i].mop2=2;
					p[i].max3=p[i].c;
					p[i].mop3=3;
				}
				else{
					p[i].max2=p[i].c;
					p[i].mop2=3;
					p[i].max3=p[i].b;
					p[i].mop3=2;
				}
			}
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c){
				p[i].max1=p[i].b;
				p[i].mop1=2;
				if(p[i].a>p[i].c){
					p[i].max2=p[i].a;
					p[i].mop2=1;
					p[i].max3=p[i].c;
					p[i].mop3=3;
				}
				else{
					p[i].max2=p[i].c;
					p[i].mop2=3;
					p[i].max3=p[i].a;
					p[i].mop3=1;
				}
			}
			else{
				p[i].max1=p[i].c;
				p[i].mop1=3;
				if(p[i].b>p[i].a){
					p[i].max2=p[i].b;
					p[i].mop2=2;
					p[i].max3=p[i].a;
					p[i].mop3=1;
				}
				else{
					p[i].max2=p[i].a;
					p[i].mop2=1;
					p[i].max3=p[i].b;
					p[i].mop3=2;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			if(p[i].max1-p[i].max2<0) cout<<i<<endl;
		}
		sort(p+1,p+1+n,cmp);
		
		for(ll i=1;i<=n;i++){
			if(d[p[i].mop1]<n/2){
				d[p[i].mop1]+=1;
				sum+=p[i].max1;
			}
			else if(d[p[i].mop2]<n/2){
				d[p[i].mop2]+=1;
				sum+=p[i].max2;
			}
			else{
				d[p[i].mop3]+=1;
				sum+=p[i].max3;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
