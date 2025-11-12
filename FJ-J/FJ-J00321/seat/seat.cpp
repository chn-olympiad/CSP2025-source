#include<bits/stdc++.h>
#define ll long long
#define N 15
using namespace std;
ll n,m,len,R,now,c,r,a[N*N];
bool cmp(ll a,ll b){return a>b;}
int main(){
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m); len=n*m;
	for(ll i=1;i<=len;i++) scanf("%lld",&a[i]);
	R=a[1]; sort(a+1,a+len+1,cmp);
	for(ll i=1;i<=len;i++) if(a[i]==R){now=i; break;}
	c=ceil(double(1.0*now/n));
	if(c%2==1) r=now-((c-1)*n);
	else r=n-(now-((c-1)*n))+1;
	printf("%lld %lld",c,r); return 0;
} 
