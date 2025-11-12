#include<bits/stdc++.h>
using namespace std;
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=1001;
int n,m;
struct node{int x,idd;}a[N];
bool cmp(node x,node y){return x.x>y.x;}
int main(){
	in("seat.in")
	out("seat.out")
	read(n),read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(a[(i-1)*n+j].x),a[(i-1)*n+j].idd=(i-1)*n+j;
	sort(a+1,a+n*m+1,cmp);
	int loc=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[(i-1)*n+j].idd==1)loc=(i-1)*n+j;
	int c=(loc-1)/n+1,r,p=(loc-1)%n+1;
	if(c%2==1)r=p;
	else r=n-p+1;
	write(c),putchar(' '),write(r);
	return 0;
}

