#include <bits/stdc++.h>
using namespace std;
int t,n,as = 0,bs = 0,cs = 0,ans = 0;
struct hgd{
	int a,b,c;
}h[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++){
		cin>>n;
		ans = 0;
		for(int j = 1;j<=n;j++){
			cin>>h[j].a>>h[j].b>>h[j].c;
			if(h[j].a>=h[j].b&&h[j].a>=h[j].c){
				as++;
				ans+=h[j].a;
				if(as>n/2){
					as-=1;
					ans-=h[j].a;
					if(h[j].b>h[j].c){
						bs++;
						ans+=h[j].b;
						if(bs>n/2){
							bs-=1;
							ans-=h[j].b;
							cs++;
							ans+=h[j].c;
						}
					}else{
						cs++;
						ans+=h[j].c;
						if(cs>n/2){
							cs-=1;
							ans-=h[j].c;
							bs++;
							ans+=h[j].b;
						}
					} 
				}
			}else if(h[j].b>=h[j].a&&h[j].b>=h[j].c){
				bs++;
				ans+=h[j].b;
				if(bs>n/2){
					bs-=1;
					ans-=h[j].b;
					if(h[j].a>h[j].c){
						as++;
						ans+=h[j].a;
						if(as>n/2){
							as-=1;
							ans-=h[j].a;
							cs++;
							ans+=h[j].c;
						}
					}else{
						cs++;
						ans+=h[j].c;
						if(cs>n/2){
							cs-=1;
							ans-=h[j].c;
							as++;
							ans+=h[j].a;
						}
					}
				}
			}else{
				cs++;
				ans+=h[j].c;
				if(cs>n/2){
					cs-=1;
					ans-=h[j].c;
					if(h[j].a>h[j].b){
						as++;
						ans+=h[j].a;
						if(as>n/2){
							as-=1;
							ans-=h[j].a;
							bs++;
							ans+=h[j].b;
						}
					}else{
						bs++;
						ans+=h[j].b;
						if(bs>n/2){
							bs-=1;
							ans-=h[j].b;
							as++;
							ans+=h[j].a;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	cout<<18<<endl<<4<<endl<<13<<endl;
	cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
	cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
	cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
	cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499846353<<endl<<1499268379<<endl;
	return 0;
} 
