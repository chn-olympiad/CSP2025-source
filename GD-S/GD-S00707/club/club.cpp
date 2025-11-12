#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,l,s,x[100005],y[100005],z[100005],u,na,nb,nc,g,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&g);
	while(g--){
		na=0;nb=0;nc=0;s=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			x[i]=0;
			y[i]=0;
			z[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			l=max({a,b,c});
			s=s+l;
			u=a+b+c-min({a,b,c})-l;
			if(l==a){
				na++;
				x[na]=l-u;
			}
			else if(l==b){
				nb++;
				y[nb]=l-u;
			}
			else{
				nc++;
				z[nc]=l-u;
			}
		}
		if(na>n/2){
			sort(x+1,x+na+1);
			for(int i=1;i<=na-n/2;i++)s=s-x[i];
		}
		if(nb>n/2){
			sort(y+1,y+nb+1);
			for(int i=1;i<=nb-n/2;i++)s=s-y[i];
		}
		if(nc>n/2){
			sort(z+1,z+nc+1);
			for(int i=1;i<=nc-n/2;i++)s=s-z[i];
		}
		printf("%lld\n",s);
	}
	return 0;//zrts1
} 
