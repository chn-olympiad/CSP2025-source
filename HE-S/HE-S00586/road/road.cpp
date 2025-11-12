//为什么要攀登？因为山就在那里。 
#include<bits/stdc++.h>
#define mrx 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
inline int read(){
	int num=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar(); 
	}
	return num*flag;
}
char wshthxdsdg[40];
inline void write(int num){
	int flag=0;
	if(!num) return putchar('0'),void();
	if(num<0) putchar('-'),num=-num;
	while(num){
		wshthxdsdg[++flag]=((num%10)^48);
		num/=10;
	}
	for(int i=flag;i;i--) putchar(wshthxdsdg[i]);
}
inline void out(int num){
	write(num);
	putchar(' ');
}
inline void print(int num){
	write(num);
	putchar('\n');
}
inline int ksm(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
int n,m,o,k;
int ans=mrx;
struct edge{
	int v,u,val;
	friend bool operator<(edge aa,edge bb){
		return aa.val<bb.val;
	}
}E[2100010];
vector<int> a[120];
int A;
int c[120];
int fa[11100];
int city;
int num;
void solve(int k){
	num=0,o=m;
	int now=1;
	while(k){
		if(k%2==1){
			city++;
			for(int i=1;i<=n;i++){
				int v=n+city,u=i,val=a[now][i-1];
				E[++o].v=v;
				E[o].u=u;
				E[o].val=val;
//				={v,u,val};
			}
			num+=c[now];
		}
		k>>=1;
		now++;
	}
}
int query(int x){
	return x==fa[x]?x:fa[x]=query(fa[x]);
}
void kru(int aaa){
	for(int i=0;i<=n+city;i++) fa[i]=i; 
	int flag=0,res=num;
	sort(E+1,E+o+1);
	for(int i=1;i<=o;i++){
		int v=E[i].v,u=E[i].u;
		int val=E[i].val;
		if((v=query(v))==(u=query(u))) continue;
		fa[v]=u;flag++;
		res+=val;
		if(flag==n+city-1) break;
	} 
	ans=min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	n=read(),m=read();k=read();
	for(int i=1;i<=m;i++){
		int v=read(),u=read(),val=read();
		E[i]={v,u,val};
	}
	int A1=0,A2=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0) A1=1;
		for(int j=1;j<=n;j++){
			int to=read();
			if(to==0) A2=0;
			a[i].push_back(to);
		}
		A|=A2;
	}
	A|=A1;
	for(int i=0;i<=(1<<k)-1;i++){
		if(!A) i=(1<<k)-1;
		o=m;num=0;
		solve(i);
		kru(i);
	}
	write(ans);
	return 0;
}
/*
逆天
感觉prim可以直接暴力过去！！！
但是我没复习全忘了怎么办
啊啊啊
要炸了！！！
好难受
*/
