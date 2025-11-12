#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
long long ans;
struct node{
	int a,b,c,maxx,cha;
}lj[100005];
bool cmp(node x,node y){
	if(x.cha!=y.cha)return x.cha>y.cha;
	return x.maxx>y.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&lj[i].a,&lj[i].b,&lj[i].c);
			lj[i].maxx=max(lj[i].a,max(lj[i].b,lj[i].c));
			if(lj[i].maxx==lj[i].a)lj[i].cha=lj[i].a-max(lj[i].b,lj[i].c);
			if(lj[i].maxx==lj[i].b)lj[i].cha=lj[i].b-max(lj[i].a,lj[i].c);
			if(lj[i].maxx==lj[i].c)lj[i].cha=lj[i].c-max(lj[i].b,lj[i].a);
		}
		int suma=0,sumb=0,sumc=0,cnta=0,cntb=0,cntc=0;
		sort(lj+1,lj+1+n,cmp);
		for(int i=1;i<=n;i++)ans+=lj[i].maxx;
		for(int i=1;i<=n;i++){
			if(lj[i].maxx==lj[i].a){
				if(cnta!=n/2)cnta++;
				else ans-=lj[i].cha;
			}
			if(lj[i].maxx==lj[i].b){
				if(cntb!=n/2)cntb++;
				else ans-=lj[i].cha;
			}
			if(lj[i].maxx==lj[i].c){
				if(cntc!=n/2)cntc++;
				else ans-=lj[i].cha;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
