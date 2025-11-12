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
const int N=2e5;
int a[N],b[N],c[N],p[N];
inline void doing(){
	n=read();m=p[1]=p[2]=p[3]=0;
	f(i,1,n){
		int x=read(),y=read(),z=read();
		m+=s=max({x,y,z});
		++p[a[i]=x==s?1:y==s?2:3];
		b[i]=s-(x+y+z-s-min({x,y,z}));
	}
	s=l=0;
	f(i,1,3)if(p[i]>n/2)s=i;
	f(i,1,n)if(a[i]==s)c[++l]=b[i];
	sort(c+1,c+l+1);
	f(i,1,l-n/2)m-=c[i];
	write(m);putchar('\n');
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)doing();
}
