#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;'0'>ch||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f; 
}
void write(int x){if(x>9)write(x/10);putchar(x%10+48);}
const int N=6e6,K=35,E=90;
struct Kazemaru{
#undef int
int a[N][36],c[N],nxt[N],t;
queue<int>Q;
inline void add(int n,char*e){
	int x=0,w;
	f(i,1,n){
		w=e[i]-E;
		if(!a[x][w])a[x][w]=++t;
		x=a[x][w];
	}
	++c[x];
}
inline void clc(){
	Q.push(0);
	for(int x,y,z;Q.size();Q.pop()){
		x=Q.front();
		c[x]+=c[z=nxt[x]];
		f(i,1,K){
			if(y=a[x][i]){
				if(x)nxt[y]=a[z][i];
				Q.push(y);
			}else{
				a[x][i]=a[z][i];
			}
		}
	}
}
#define int long long
}AC;
char a[N],b[N],c[N];
inline void rd(char U){
	scanf("%s %s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1),p=0,q=0;
	f(i,1,n)if(a[i]!=b[i])p=p?p:i,q=i;
	if(n!=m||!p)return c[s=1]=U,void();s=0;
	f(i,1,p-1)c[++s]=a[i];c[++s]='{';
	f(i,p,q)c[++s]=a[i];c[++s]='|';
	f(i,p,q)c[++s]=b[i];c[++s]='}';
	f(i,q+1,n)c[++s]=b[i];
}
inline void doing(){
	n=read();m=read();
	f(i,1,n)rd('['),AC.add(s,c);
	AC.clc();
	f(i,1,m){
		rd(']');
		int x=0,y=0;
		f(i,1,s)y+=AC.c[x=AC.a[x][c[i]-E]];
		write(y);putchar('\n');
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;
	while(t--)doing();
}
