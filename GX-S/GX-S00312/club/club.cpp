#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=1e5+10;
int n,A=1,B=1;
struct nd{int a,b,c,id,as;} r[N];
int f[40][40][40][40];
void work1(){
	memset(f,0,sizeof f);
	int j=n/2,k=n/2,l=n/2,ans=0;
	For(i,1,n) For(j,0,n/2) For(k,0,n/2) For(l,0,n/2){
		if(j!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j-1][k][l]+r[i].a);
		if(k!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k-1][l]+r[i].b);
		if(l!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l-1]+r[i].c);
	}
	printf("%lld\n",f[n][n/2][n/2][n/2]);
}
void work2(){
	For(i,1,n)
		r[i].as=r[i].a-r[i].b;
	sort(r+1,r+n+1,[](nd r1,nd r2){
		if(r1.as==r2.as) return r1.a>r2.a;
		return r1.as>r2.as;
	});
	int cnt=0,ans=0;
	For(i,1,n){
		if(cnt<n/2){
			ans+=r[i].a; cnt++;
		}
		else ans+=r[i].b;
	}
	printf("%lld\n",ans);
}
void work3(){
	sort(r+1,r+n+1,[](nd r1,nd r2){
		return r1.a>r2.a;
	});
	int ans=0;
	For(i,1,n/2) ans+=r[i].a;
	printf("%lld\n",ans);
}
void workC(){
	int ans=0;
	For(i,1,n)
		ans+=max(r[i].a,max(r[i].b,r[i].c));
	printf("%lld\n",ans);
}

signed main(){ // 70pts
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		For(i,1,n){
			int a=read(),b=read(),c=read();
			r[i]={a,b,c,i};
			if(c!=0) B=0;
			if(b!=0) A=0;
		}
		if(n<=30)
			work1();
		else if(B) work2();
		else if(A) work3();
		else workC();

	}
	
	
	return 0;
}