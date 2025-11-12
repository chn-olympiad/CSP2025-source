#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,x,y,z,ans=0,m[114514],tot=0;

bool flag1=1,flag2=1,vis[114514];

struct node1{
	ll a,b,c;
}e[114514];

struct node2{
	ll a,b;
	bool c;
}p[114514];

bool awa1(node1 s,node1 t)
{
	if(s.a!=t.a) return s.a>t.a;
	else if(s.b!=t.b) return s.b>t.b;
	else return s.c>t.c;
}

bool awa2(node2 s,node2 t)
{
	return s.a>t.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		memset(vis,0,sizeof(vis));
		ans=0,x=n,y=0,z=0,tot=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
			if(e[i].b!=0||e[i].c!=0) flag1=0;
			if(e[i].c!=0) flag2=0;
		}
		sort(e+1,e+1+n,awa1);
		if(flag1){
			for(ll i=1;i<=n/2;i++) ans+=e[i].a;
			printf("%lld\n",ans);
			continue;
		}
		else if(flag2){
			for(ll i=1;i<=n;i++) ans+=e[i].a,m[i]=e[i].b-e[i].a;
			sort(m+1,m+n+1);
			for(ll i=1;i<=n/2;i++){
				ans+=m[n-i+1];
			}
			printf("%lld\n",ans);
			continue;
		}
		else{
			for(ll i=1;i<=n;i++){
				ans+=e[i].a;
				tot++;
				p[tot].a=e[i].b-e[i].a;
				p[tot].b=i;
				p[tot].c=0;
				tot++;
				p[tot].a=e[i].c-e[i].a;
				p[tot].b=i;
				p[tot].c=1;
			}
			sort(p+1,p+tot+1,awa2);
			for(ll i=1;i<=tot;i++){
				if(x<=0) break;
				if(vis[p[i].b]) continue;
				if((y>=n/2&&!p[i].c)||(z>=n/2&&p[i].c)) continue;
				if(x<=n/2&&p[i].a<=0) break;
				ans+=p[i].a;
				x--;
				if(!p[i].c) y++;
				else z++;
				vis[p[i].b]=1;
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
} 
