#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
ll n,ans;
struct del{
	ll d1,d2;
	ll c1,c2;
	bool operator <(const del b)const{
		if(d1!=b.d1) return d1>b.d1;
		return d2>b.d2;
	}
};
priority_queue<del> c1,c2,c3;
void init(){
	ans=0;
	while(!c1.empty()) c1.pop();
	while(!c2.empty()) c2.pop();
	while(!c3.empty()) c3.pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		ll hlf=(n>>1);
		for(int i=1;i<=n;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				ans+=a;
				if(b>=c){
					del tmp={a-b,b-c,2,3};
					c1.push(tmp);
				}
				else{
					del tmp={a-c,c-b,3,2};
					c1.push(tmp);
				}
			}
			else if(b>=a&&b>=c){
				ans+=b;
				if(a>=c){
					del tmp={b-a,a-c,1,3};
					c2.push(tmp);
				}
				else{
					del tmp={b-c,c-a,3,1};
					c2.push(tmp);
				}
			}
			else{
				ans+=c;
				if(a>=b){
					del tmp={c-a,a-b,1,2};
					c3.push(tmp);
				}
				else{
					del tmp={c-b,b-a,2,1};
					c3.push(tmp);
				}
			}
			for(int j=1;j<=3;j++){
				if(c1.size()>hlf){
					del tmp=c1.top();
					c1.pop();
					ans-=tmp.d1;
					if(tmp.c1==2) c2.push({tmp.d2,INT_MAX,3,1});
					else c3.push({tmp.d2,INT_MAX,2,1});
				}
				if(c2.size()>hlf){
					del tmp=c2.top();
					c2.pop();
					ans-=tmp.d1;
					if(tmp.c1==1) c1.push({tmp.d2,INT_MAX,3,2});
					else c3.push({tmp.d2,INT_MAX,1,2});
				}
				if(c3.size()>hlf){
					del tmp=c3.top();
					c3.pop();
					ans-=tmp.d1;
					if(tmp.c1==1) c1.push({tmp.d2,INT_MAX,2,3});
					else c2.push({tmp.d2,INT_MAX,1,3});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
