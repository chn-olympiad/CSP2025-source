#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ct,u,v,ts,ans,c[15],a[15][10005],f[10015];
struct lyt{
	long long u,v,w;
}p[2000005];
bool cmp1(lyt A,lyt B){
	return A.w<B.w;
}
bool A,At;
int g_f(int x){
	return f[x]=x==f[x]?x:g_f(f[x]); 
}
char *ic,*oc,ibuf[40000005],obuf[105],tbuf[15];
int len;
void read(long long &x){
	x=0;
	while(*ic<'0'||*ic>'9')ic++;
	while(*ic>='0'&&*ic<='9')x=x*10+(*ic++-'0');
}
void write(long long &x){
	len=0;
	do{
		tbuf[++len]=x%10+48;
		x/=10;
	}while(x);
	for(int i=len;i>0;i--){
		*oc++=tbuf[i];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fread(ibuf,1,40000000,stdin);
	ic=ibuf;oc=obuf;
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(p[i].u);read(p[i].v);read(p[i].w);
	}
	ct=m;A=1;
	for(int i=1;i<=k;i++){
		read(c[i]);
		A&=(c[i]==0);At=0;
		for(int j=1;j<=n;j++){
			read(a[i][j]);
			At|=(a[i][j]==0);
		}
		A&=At;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			ct++;
			p[ct].u=j;p[ct].v=n+i;p[ct].w=a[i][j];
		}
	}
	sort(p+1,p+ct+1,cmp1);
	if(A){
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		for(int i=1;i<=ct;i++){
			u=g_f(p[i].u);v=g_f(p[i].v);
			if(u!=v){
				f[u]=v;
				ans+=p[i].w;
			}
		}
		write(ans);
		fwrite(obuf,1,oc-obuf,stdout);
		return 0;
	}
	ans=1e18;
	for(int e=0;e<(1<<k);e++){
		ts=0;
		for(int i=1;i<=k;i++)if(e&(1<<(i-1)))ts+=c[i];
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		for(int i=1;i<=ct;i++){
			if(p[i].v>n&&(e&(1<<(p[i].v-n-1)))==0)continue;
			u=g_f(p[i].u);v=g_f(p[i].v);
			if(u!=v){
				f[u]=v;
				ts+=p[i].w;
			}
		}
		ans=min(ans,ts);
	}
	write(ans);
	fwrite(obuf,1,oc-obuf,stdout);
	return 0;
}
