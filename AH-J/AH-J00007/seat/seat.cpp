#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,sz,h[105],s,x,y,i;
bool cmp(int a,int b) {return a>b;}
int main(void) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	sz=n*m;
	for(i=0;i<sz;++i) scanf("%d",&h[i]);
	s=h[0];
	sort(h,h+sz,cmp);
	for(i=0;i<sz;++i)
		if(h[i]==s) break;
	s=i;
	x=s/n+1;
	if(x&1) y=s%n+1;
	else y=n-s%n;
	printf("%d %d",x,y);
	return 0;
}
