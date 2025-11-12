#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
struct note{
	ll a,b,c;
	ll atob,btoc,atoc;
	int cli;
}a[100005];
bool cmp(note x,note y){
	if(x.cli!=y.cli)return x.cli<y.cli;
	ll xma,yma;
	
	if(x.cli==1) xma=min(x.atob,x.atoc);
	if(x.cli==2) xma=min(x.atob,x.btoc);
	if(x.cli==3) xma=min(x.atoc,x.btoc);
	
	if(y.cli==1) yma=min(y.atob,y.atoc);
	if(y.cli==2) yma=min(y.atob,y.btoc);
	if(y.cli==3) yma=min(y.atoc,y.btoc);
	
	return xma>yma;
}
ll n;
int main(){
	fin("club.in");
	fout("club.out");
	int _=0;
	cin>>_;
	while(_--){
		sf("%lld",&n);
		for(int i=1;i<=n;i++){
			ll x,y,z,cli;
			sf("%lld%lld%lld",&x,&y,&z);
			if(z>x&&z>y)cli=3;
			else if(x>y)cli=1;
			else cli=2;
			a[i]={x,y,z,abs(x-y),abs(y-z),abs(x-z),cli};
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].cli<<" "<<(a[i].atob==abs(a[i].a-a[i].b))<<" "<<(a[i].btoc==abs(a[i].b-a[i].c))<<" "<<(a[i].atoc==abs(a[i].a-a[i].c))<<"\n";
//		}
		/*down*/
		ll tmpa=0,tmpb=0,tmpc=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i].cli==1)sum+=a[i].a,tmpa++;
			else if(a[i].cli==2)sum+=a[i].b,tmpb++;
			else if(a[i].cli==3)sum+=a[i].c,tmpc++;
		}
		//cout<<tmpa<<" "<<tmpb<<" "<<tmpc;
		while(tmpa>n/2)sum-=min(a[tmpa].atob,a[tmpa].atoc),tmpa--;
		while(tmpb>n/2)sum-=min(a[tmpa+tmpb].atob,a[tmpa+tmpb].btoc),tmpb--;
		while(tmpc>n/2)sum-=min(a[tmpa+tmpb+tmpc].btoc,a[tmpa+tmpb+tmpc].atoc),tmpc--;
		pf("%lld\n",sum);
	}
	return 0;
}

