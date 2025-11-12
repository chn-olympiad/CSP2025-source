#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,f=1;
bool cmp(int x,int y) {return x>y;}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]); s=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=1,x=1,y=1;i<=n*m;i++) {
		if(a[i]==s) {printf("%d %d\n",x,y); return 0;}
//		printf("%d %d %d\n",x,y,a[i]);
		if(y==n) x++,f=-1;
		else if(y==1&&x!=1) x++,f=1;
		else y+=f;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
