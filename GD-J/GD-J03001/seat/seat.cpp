#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;
int dis[N],vis[N],kis[N],f[N];

void read(int &x){
	x=0;int ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(int x){
	if(x<0){
		putchar('-');x=-x;
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

struct P{
	int x,id;
}v[N];

bool cmp(P a,P b){
	return a.x>b.x;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n*m;i++) read(v[i].x),v[i].id=i;
	sort(1+v,1+v+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(v[i].id==1){
			int x=(i%n==0?i/n:(i/n+1)),z=i%n==0?n:i%n;
			int y=(x%2==1?z:n-z+1);
			wk(x),write(y);return 0;
		}
	}
	return 0;
}/*

2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
