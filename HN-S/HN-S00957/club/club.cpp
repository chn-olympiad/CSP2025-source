#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){res=(res<<1)+(res<<3)+ch-'0';ch=getchar();}
	return res*f;
}
void write(int x){
	if(x<0){putchar('-');write(-x);return;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int _,n,tot1,tot2,tot3,now;
struct node{int id,val;}v[114514];
struct stu{int a1,a2,a3;}a[114514];
bool cmp(node x,node y){return x.val<y.val;}
void solve(){
	memset(v,0,sizeof(v));memset(a,0,sizeof(a));
	tot1=tot2=tot3=now=0;n=read();
	for(int i=1;i<=n;++i){a[i].a1=read();a[i].a2=read();a[i].a3=read();}
	for(int i=1;i<=n;++i){
		if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){++tot1;now+=a[i].a1;}
		else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){++tot2;now+=a[i].a2;}
		else{++tot3;now+=a[i].a3;}
	}
	while(tot1>n>>1||tot2>n>>1||tot3>n>>1){
		if(tot1>n>>1){
			int cha=tot1-(n>>1),pos=0;
			for(int i=1;i<=n;++i){
				if(a[i].a1<a[i].a2||a[i].a1<a[i].a3)continue;
				++pos;
				if(a[i].a2>=a[i].a3){v[pos]=(node){2,a[i].a1-a[i].a2};}
				else{v[pos]=(node){3,a[i].a1-a[i].a3};}
			}
			sort(v+1,v+pos+1,cmp);tot1=n>>1;
			for(int i=1;i<=cha;++i){
				if(v[i].id==2)++tot2;
				else ++tot3;
				now-=v[i].val;
			}
		}
		memset(v,0,sizeof(v));
		if(tot2>n>>1){
			int cha=tot2-(n>>1),pos=0;
			for(int i=1;i<=n;++i){
				if(a[i].a2<=a[i].a1||a[i].a2<a[i].a3)continue;
				++pos;
				if(a[i].a1>=a[i].a3){v[pos]=(node){1,a[i].a2-a[i].a1};}
				else{v[pos]=(node){3,a[i].a2-a[i].a3};}
			}
			sort(v+1,v+pos+1,cmp);tot2=n>>1;
			for(int i=1;i<=cha;++i){
				if(v[i].id==1)++tot1;
				else ++tot3;
				now-=v[i].val;
			}
		}
		memset(v,0,sizeof(v));
		if(tot3>n>>1){
			int cha=tot3-(n>>1),pos=0;
			for(int i=1;i<=n;++i){
				if(a[i].a3<=a[i].a1||a[i].a3<=a[i].a2)continue;
				++pos;
				if(a[i].a1>=a[i].a2){v[pos]=(node){1,a[i].a3-a[i].a1};}
				else{v[pos]=(node){2,a[i].a3-a[i].a2};}
			}
			sort(v+1,v+pos+1,cmp);tot3=n>>1;
			for(int i=1;i<=cha;++i){
				if(v[i].id==1)++tot1;
				else ++tot2;
				now-=v[i].val;
			}
		}
	}
	write(now);putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_=read();while(_--)solve();
	return 0;
}
//100+56~72+0~5+8~12=164~189
