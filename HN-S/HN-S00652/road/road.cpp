#include<bits/stdc++.h>
#define int long long
#define qwe(i,l,r) for(int i=l;i<=r;++i)
#define ewq(i,l,r) for(int i=l;i>=r;--i)
#define mkp make_pair
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int Min(int a,int b){
	return a<b?a:b;
}
const int M=1e6+5,N=1e4+5,K=12;
struct asd{
	int x,y,w;
}a[M],b[N+K*N],c[N];
bool cmp(asd f1,asd f2){
	return f1.w<f2.w;
}
int n,m,k,f[N+K],ans,top,e[K][N];
int fi(int x){
	return f[x]==x?f[x]:f[x]=fi(f[x]);
}
//so join a bian = n+nk
//O((n+nk)*(2^k))=2^k*(nk log nk)
int _(int cnt){
	int sum=0,x=cnt;
//	qwe(i,1,top)printf("%lld %lld %lld\n",b[i].x,b[i].y,b[i].w);
	sort(b+1,b+top+1,cmp);
	qwe(i,1,n+k)f[i]=i;
	qwe(i,1,top){
//		printf("%lld %lld %lld %lld\n",b[i].x,b[i].y,fi(b[i].x),fi(b[i].y));
//		if(i<=(cnt-n)*n&&b[i].w!=0) {
//			puts("Wrong!");
//		}
		if(fi(b[i].x)==fi(b[i].y))continue;
		f[fi(b[i].y)]=fi(b[i].x);
		sum+=b[i].w;
		--cnt;
//		cout<<sum<<'\n';
		if(cnt==1)return sum;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	qwe(i,1,m){
		a[i].x=read();
		a[i].y=read();
		a[i].w=read();
	}
	qwe(i,1,k)qwe(j,0,n)e[i][j]=read();
	sort(a+1,a+m+1,cmp);
	qwe(i,1,n)f[i]=i;
	qwe(i,1,m){
		if(fi(a[i].x)==fi(a[i].y))continue;
		f[fi(a[i].y)]=fi(a[i].x);
		ans+=a[i].w;
		c[++top]=a[i];
	}
	qwe(j,1,(1<<k)-1){
		qwe(i,1,n-1)b[i]=c[i];
		top=n-1;
		int cnt=n,op=0;
		qwe(i,1,k){
			if((1<<(i-1))&j){
				++cnt;
				op+=e[i][0];
				qwe(l,1,n){
					++top;
					b[top].x=i+n;
					b[top].y=l;
					b[top].w=e[i][l];
				}
			}
		}
		int __=_(cnt);
//		printf("%lld %lld %lld\n",__,op,cnt);
		ans=Min(ans,__+op);
	}
	cout<<ans;
	return 0;
}
