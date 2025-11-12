#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
ll t,n,ans=0,cha=0,chb=0,chc=0;
struct man{
	ll a,b,c;
	bool vis;
}m[N];
bool tmp1(man x,man y){return x.a>y.a;};
bool tmp2(man x,man y){return x.b>y.b;};
bool tmp3(man x,man y){return x.c>y.c;};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(m,0,sizeof(m));
		ans=0;
		n=0;
		cha=0;
		chb=0;
		chc=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&m[i].a,&m[i].b,&m[i].c);
			ll temp=min(m[i].a,min(m[i].b,m[i].c));
			m[i].a-=temp;
			m[i].b-=temp;
			m[i].c-=temp;
			ans+=temp;
		}
		sort(m+1,m+n+1,tmp1);
		for(int i=1;i<=n;i++){
			if(cha>=n>>1) break;
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c&&!m[i].vis){
				ans+=m[i].a;
				m[i].vis=true;
				cha++;
			}
		}
		for(int i=1;i<=n;i++) m[i].a=-10;
		sort(m+1,m+n+1,tmp2);
		for(int i=1;i<=n;i++){
			if(chb>=n>>1) break;	
			if(m[i].b>=m[i].c&&!m[i].vis){
				ans+=m[i].b;
				m[i].vis=true;
				chb++;
			}
		}
		for(int i=1;i<=n;i++) m[i].b=-10;
		sort(m+1,m+n+1,tmp3);
		for(int i=1;i<=n;i++){
			if(chc>=n>>1) break;
			if(!m[i].vis){
				ans+=m[i].c;
				m[i].vis=true;
				chc++;
			}
		}
		for(int i=1;i<=n;i++) m[i].c=-10;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
