#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int M = 1e5+5;
int t;
ll ma,mb,mc,md;
ll n;
struct T{
	ll a,b,c,d;
}e[M];
ll visa[M], visb[M], visc[M],visd[M];
ll ans;
struct G{
	ll a,b;
}p[M];
bool cmp(G &x, G &y)
{
	return x.b<y.b;
}
inline long long rd(){
	ll x=0,f=1;
	char c; c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c-'0');c=getchar();}
	return x*f;}
inline void pu(long long x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) pu(x/10);
	putchar((x%10+'0'));}
inline void solve(){
	n=rd();
	ma=mb=mc=md=0;
	ans=0;
	for(int i=1;i<=n;i++){
		visa[i]=visb[i]=visc[i]=visd[i]=0;
		e[i].a=e[i].b=e[i].c=e[i].d=0;
		p[i].a=p[i].b=0;
	}
	for(int i=1;i<=n;i++){
		e[i].a=rd(),e[i].b=rd(),e[i].c=rd();
		ans+=max(max(e[i].a,e[i].b),e[i].c);
		if(e[i].a>e[i].b&&e[i].a>e[i].c){//a
			ma++; 
			e[i].d=e[i].a-max(e[i].b,e[i].c);
			
			visa[ma]=i;
			}else{
		if(e[i].b>e[i].c&&e[i].b>e[i].a){//b
			mb++; 
			e[i].d=e[i].b-max(e[i].a,e[i].c);
			visb[mb]=i;
			}else{
		if(e[i].c>e[i].a&&e[i].c>e[i].b){//c
			mc++; 
			visc[mc]=i; 
			e[i].d=e[i].c-max(e[i].b,e[i].a);
			}
			else{//other
				md++;
				visd[md]=i;
				}
			}
		}
	}
	//cout<<ma<<" "<<mb<<" "<<mc<<" "<<md<<endl;
	//cout<<ans<<endl;
	if(ma>n/2){
		for(int i=1;i<=ma;i++){
			p[i].b = e[visa[i]].d;
		}
		sort(p+1,p+ma+1,cmp);
		for(int i=1;i<=ma-n/2;i++){
			ans-=p[i].b;
		}
	}
	if(mb>n/2){
		for(int i=1;i<=mb;i++){
			p[i].b = e[visb[i]].d;
		}
		sort(p+1,p+mb+1,cmp);
		for(int i=1;i<=mb-n/2;i++){
			ans-=p[i].b;
		}
	}
	if(mc>n/2){
		for(int i=1;i<=mc;i++){
			p[i].b = e[visc[i]].d;
		}
		sort(p+1,p+mc+1,cmp);
		for(int i=1;i<=mc-n/2;i++){
			
			ans-=p[i].b;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd();
	while(t--){
		solve();
	}
	return 0;
}
