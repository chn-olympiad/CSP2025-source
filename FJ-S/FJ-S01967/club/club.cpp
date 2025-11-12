#include<bits/stdc++.h>
using namespace std;
const int M=99999,N=100010;
int q[N*3];
struct node{
	int a,b,c,f;
}p[N];
int lar(int x){
	return max(p[x].a,max(p[x].b,p[x].c));
}
void deal(int x,int &h,int &k,int &l,int &ret){
	int m=lar(x);
	ret+=m;
	if(m==p[x].a) h++,p[x].f=1;
	else if(m==p[x].b) k++,p[x].f=2;
	else if(m==p[x].c) l++,p[x].f=3;
}
int print(int s,int res,int cnt,int o,int l){
	for(int i=1;i<=o;i++){
		if(p[i].f==l){
			if(l==1) q[++cnt]=lar(i)-max(p[i].b,p[i].c);
			if(l==2) q[++cnt]=lar(i)-max(p[i].a,p[i].c);
			if(l==3) q[++cnt]=lar(i)-max(p[i].a,p[i].b);
		}
	}sort(q+1,q+cnt+1);
	for(int i=1;i<=s;i++) res-=q[i];
	for(int i=1;i<=cnt;i++) q[i]=0;
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,u=0,v=0,w=0,ans=0,top=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		for(int i=1;i<=n;i++) deal(i,u,v,w,ans);
		if(u>n/2) ans=print(u-n/2,ans,top,n,1);
		else if(v>n/2) ans=print(v-n/2,ans,top,n,2);
		else if(w>n/2) ans=print(w-n/2,ans,top,n,3);
		printf("%d\n",ans);
	}
	return 0;
}
