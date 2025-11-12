#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,t,mc[100005],A,b,c,ans;
struct sor{
	int mx,mc,sx,sc;
}a[100005];
inline bool cmp(sor u,sor v){
	return u.mc>v.mc;
}
inline void a_add(sor x){
	if(2*A>=n)x.mx-=x.mc;
	A++;
	ans+=x.mx;
}
inline void b_add(sor x){
	if(2*b>=n)x.mx-=x.mc;
	b++;
	ans+=x.mx;
}
inline void c_add(sor x){
	if(2*c>=n)x.mx-=x.mc;
	c++;
	ans+=x.mx;
}
inline void red(int x,int y,int z,int i){
	if(x>=y&&x>=z){
		a[i].mx=x,a[i].sx=1;
		if(y>=z)a[i].mc=x-y,a[i].sc=2;
		else a[i].mc=x-z,a[i].sc=3;
	}
	else if(y>=x&&y>=z){
		a[i].mx=y,a[i].sx=2;
		if(x>=z)a[i].mc=y-x,a[i].sc=1;
		else a[i].mc=y-z,a[i].sc=3;
	}
	else {
		a[i].mx=z,a[i].sx=3;
		if(y>=x)a[i].mc=z-y,a[i].sc=2;
		else a[i].mc=z-x,a[i].sc=1;
	}
}
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		A=0,b=0,c=0,ans=0;
		n=read();
		for(int i=1,x,y,z;i<=n;i++){
			x=read(),y=read(),z=read();
			red(x,y,z,i);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].sx==1){
				a_add(a[i]);
			}
			if(a[i].sx==2){
				b_add(a[i]);
			}
			if(a[i].sx==3){
				c_add(a[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
