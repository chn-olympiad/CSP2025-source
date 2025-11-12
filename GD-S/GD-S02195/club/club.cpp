#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,ans,n;
struct nb{
	int a,b,c;
}d[N];
bool na(nb x,nb y){
	return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);
}
bool nd(nb x,nb y){
	return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);
}
bool nc(nb x,nb y){
	return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		int a=0,b=0,c=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c) a++;
			else if(d[i].b>=d[i].a&&d[i].b>=d[i].c) b++;
			else if(d[i].c>=d[i].b&&d[i].c>=d[i].a) c++;
			else a++;
		}
		if(a<=(n>>1)&&b<=(n>>1)&&c<=(n>>1)){
			for(int i=1;i<=n;i++) ans+=max(d[i].a,max(d[i].b,d[i].c));
			printf("%lld\n",ans);
			continue;
		} 
		if(a>(n>>1)){
			sort(d+1,d+n+1,na);
			for(int i=1;i<=(n>>1);i++) ans+=max(d[i].b,d[i].c);
			for(int i=(n>>1)+1;i<=n;i++) ans+=d[i].a;
			printf("%lld\n",ans);
		} 
		else if(b>(n>>1)){
			sort(d+1,d+n+1,nd);
			for(int i=1;i<=(n>>1);i++) ans+=max(d[i].a,d[i].c);
			for(int i=(n>>1)+1;i<=n;i++) ans+=d[i].b;
			printf("%lld\n",ans);
		} 
		else if(c>(n>>1)){
			sort(d+1,d+n+1,nc);
			for(int i=1;i<=(n>>1);i++) ans+=max(d[i].b,d[i].a);
			for(int i=(n>>1)+1;i<=n;i++) ans+=d[i].c;
			printf("%lld\n",ans);
		} 
	}
	return 0;
} 
