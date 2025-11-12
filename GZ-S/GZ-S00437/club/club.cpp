//GZ-S00437 华东师范大学附属贵阳学校 邱宣然 
#include<bits/stdc++.h>
using namespace std;
#define in cin
#define ou cout
#define ll long long
#define ii int
#define ss string
#define vv void
#define dd double
#define co const int
#define rr return
#define br break
#define con continue
co N=6e6+10;
ll x[N][3];
ll f(ll q,ll w,ll a,ll m,ll k){
	if(q==a){
		rr m;
	}
	rr max(f(q+1,w,a,m,k),f(q,(w+1)%3,a,m,k));
}
vv ai()
{
	ll a,m=0;
	in>>a;
	ll u1=a/2,u2=a/2,u3=a/2;
	for(ll i=1;i<=a;i++){
		in>>x[i][1]>>x[i][2]>>x[i][3];
	}
	ou<<f(1,1,a,0,0)<<endl;
}
int main()
{
	freopen("club.in",'r',std.in);
	freopen("club.out",'w',std.out);
	ll t=1;
	in>>t;
	while(t--){
		ai();
	}
	rr 0;
}
