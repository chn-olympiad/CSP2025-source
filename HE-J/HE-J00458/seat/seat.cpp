#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &a) {
	a=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		a=a*10+c-48;
		c=getchar();
	}
	a*=f;
}
void wr(int a) {
	if(a>9) {
		wr(a/10);
	}
	putchar(a%10+48);
}
void write(int a) {
	if(a<0) {
		a=-a;
	}
	wr(a);
	putchar(' ');
}
int n,m;
struct name {
	int id,s;
} a[150],pos[11][11];
bool cmp(name a,name b) {
	return a.s>b.s;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);
	read(m);
	for(int i=1; i<=n*m; i++) {
		read(a[i].s);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int fg=1;
	int x=1,y=1;
	for(int i=1; i<=n*m; i++) {
		pos[x][y]=a[i];
		if(x==n&&fg==1) {
			fg=2;
		} else if(fg==2) {
			fg=3;
		} else if(x==1&&fg==3) {
			fg=4;
		} else if(fg==4){
			fg=1;
		}
		if(fg==1) {
			x++;
		} else if(fg==2||fg==4) {
			y++;
		} else {
			x--;
		}
	}
	for(int i=1; i<=n+1; i++) {
		for(int j=1; j<=m+1; j++) {
			if(pos[i][j].id==1){
				write(j);
				write(i);
				return 0;
			}
		}
	}
	return 0;
}
