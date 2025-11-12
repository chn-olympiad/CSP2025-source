#include<bits/stdc++.h>
using namespace std;
long long ttt,n,l[3000000],h[1000000],f[1000000],cn,cnt,xx,t,yy,s,sa[3000000],ans;
long long aaa,bbb,xa[1000000];
struct lu{
	long long x,y,w,s;
}e[3000000];
void qsort(long long l,long long r){
	long long i=l,j=r,mid=xa[(l+r)/2];
	while(i<=j){
		while(xa[i]>mid) i++;
		while(xa[j]<mid) j--;
		if(i<=j){
			swap(xa[i],xa[j]);
			i++,j--;
		}
	}
	if(i<r) qsort(i,r);
	if(j>l) qsort(l,j);
}
void jia(long long x,long long y,long long w){
	e[++cn].x=h[x];
	e[cn].y=y;
	e[cn].w=w;
	e[cn].s=cn;
	h[x]=cn;
	return ;
}
bool sp(){
	s=1;
	sa[1]=0;
	f[0]=0;
	for(long long i=1;i<=n+4;i++) f[i]=999999999;
	for(long long i=1;i<=s;i++){
		for(long long j=h[sa[i]];j!=-1;j=e[j].x){
			if(f[sa[i]]+e[j].w<f[e[j].y]&&l[e[j].s]){
				sa[++s]=e[j].y;
				f[e[j].y]=f[sa[i]]+e[j].w;
			}
		}
	}
	if(f[n+4]<0) return 1;
	return 0;
}
long long dp(long long x,long long ll){
	if(x==n+4||ll==0) return ll;
	for(long long i=h[x];i!=-1;i=e[i].x){
		if(l[e[i].s]&&f[x]+e[i].w==f[e[i].y]){
			t=dp(e[i].y,min(ll,l[e[i].s]));
			if(t!=0){
				l[e[i].s]-=t;
				l[e[i].s^1]+=t;
				return t;
			}
		}
	}
	return 0;
}
void work(){
	cin>>n;
	cn=-1;
	aaa=bbb=1;
	for(long long i=0;i<=n+4;i++) h[i]=-1;
	for(long long i=1;i<=n;i++){
		jia(0,i,0);
		l[cn]=1;
		jia(i,0,0);
		l[cn]=0;
		cin>>xx;
		xa[i]=xx;
		jia(i,n+1,-xx);
		l[cn]=1;
		jia(n+1,i,xx);
		l[cn]=0;
		cin>>xx;
		if(xx!=0) aaa=0;
		jia(i,n+2,-xx);
		l[cn]=1;
		jia(n+2,i,xx);
		l[cn]=0;
		cin>>xx;
		if(xx!=0) bbb=0;
		jia(i,n+3,-xx);
		l[cn]=1;
		jia(n+3,i,xx);
		l[cn]=0;
	}
	if(aaa&&bbb){
		ans=0;
		qsort(1,n);
		for(long long i=1;i<=n/2;i++) ans+=xa[i];
		printf("%lld\n",ans);
	}
	jia(n+1,n+4,0);
	l[cn]=n/2;
	jia(n+4,n+1,0);
	l[cn]=0;
	jia(n+2,n+4,0);
	l[cn]=n/2;
	jia(n+4,n+2,0);
	l[cn]=0;
	jia(n+3,n+4,0);
	l[cn]=n/2;
	jia(n+4,n+3,0);
	l[cn]=0;
	ans=0;
	while(sp()){
		dp(0,999999999);
		ans+=f[n+4];
	}
	printf("%lld\n",-ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>ttt;
	while(ttt){
		ttt--;
		work();
	}
	return 0;
} 
