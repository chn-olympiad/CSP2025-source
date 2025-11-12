#include <bits/stdc++.h>
#define pa pair <int,int>
#define int long long
#define y second
#define x first
using namespace std;
const int N=1e2+10;

inline int read(){
	int ans=0;bool f=0;char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return (f?-ans:ans);
}

inline void write(int x,string s=""){
	if(x<0) x=-x,putchar('-');
	static char a[50],k=0;
	do{a[short(++k)]=x%10,x/=10;}while(x);
	while(k) putchar(a[short(k--)]|48);
	if(s=="\n") putchar('\n'); else if(s==" ") putchar(' ');
}

int n,m,p,a=1,b=1,k=1;
pa g[N];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;++i) g[i].x=read(),g[i].y=i;
	stable_sort(g+1,g+n*m+1,greater<pa>() );
	for(int i=1;i<=n*m;++i){
		if(g[i].y==1){
			p=i;
			break;
		}
	}
	a=p/n,b=p%n;
	if(b!=0) a++;
	else b=n;
	if(a%2==0) b=n-b+1;
	write(a," "),write(b,"\n");
	return 0;
}
