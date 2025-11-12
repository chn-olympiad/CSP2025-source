#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=100001+5;
LL n,m,T,a[N][3],ans;
struct S{
	LL c,tc,da;
}b[N];
struct E{
	LL x,pos;
}tot[3];
bool cmp(S x,S y)
{
	return x.da<y.da;
}
bool cmp2(E x,E y)
{
	return x.x>y.x;
}
LL lmax(LL x,LL y){
	if(x>y)return x;
	return y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(tot,0,sizeof(tot));
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			E ma[3];
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			ma[0].x=a[i][0];ma[0].pos=0;
			ma[1].x=a[i][1];ma[1].pos=1;
			ma[2].x=a[i][2];ma[2].pos=2;
			sort(ma,ma+3,cmp2);
			b[i].c=ma[0].pos;
			b[i].tc=ma[0].x;ans+=ma[0].x;
			b[i].da=ma[0].x-ma[1].x;
			tot[b[i].c].x++;
		}
		sort(b+1,b+n+1,cmp);
		tot[0].pos=0;tot[1].pos=1;tot[2].pos=2;
		sort(tot,tot+3,cmp2);
		int pp=1;
		while(tot[0].x>n/2)
		{
			if(b[pp].c==tot[0].pos)
			{ans-=b[pp].da;tot[0].x--;}
			pp++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
