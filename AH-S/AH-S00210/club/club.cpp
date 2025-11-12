#include<bits/stdc++.h>
using namespace std;
struct o{
	int a,b,c,d;
}a[100005];
int v[100005],p[100005],g[100005];
bool cmp(o x,o y){
	return x.d>y.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,s;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			s+=a[i].a;
			a[i].d=1;
		}
		x=n;
		for(int i=1;i<=n;i++){
			if(a[i].b>a[i].a){
				x--;
				y++;
				s=s-a[i].a+a[i].b;
				a[i].d=2;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].d==2){
				if(a[i].c>a[i].b){
					y--;
					z++;
					s=s-a[i].b+a[i].c;
					a[i].d=3;
				}
			}else{
				if(a[i].c>a[i].a){
					x--;
					z++;
					s=s-a[i].a+a[i].c;
					a[i].d=3;
				}
			}
		}
		if(x>n/2){
			int hh=0;
			for(int i=1;i<=n;i++){
				if(a[i].d==1){
					hh++;
					g[hh]=min(a[i].a-a[i].b,a[i].a-a[i].c);
				}
			}
			sort(g+1,g+hh+1);
			int uu=x-n/2;
			for(int i=1;i<=uu;i++)s-=g[i];
		}
		if(y>n/2){
			int hh=0;
			for(int i=1;i<=n;i++){
				if(a[i].d==2){
					hh++;
					g[hh]=min(a[i].b-a[i].a,a[i].b-a[i].c);
				}
			}
			sort(g+1,g+hh+1);
			int uu=y-n/2;
			for(int i=1;i<=uu;i++)s-=g[i];
		}
		if(z>n/2){
			int hh=0;
			for(int i=1;i<=n;i++){
				if(a[i].d==3){
					hh++;
					g[hh]=min(a[i].c-a[i].a,a[i].c-a[i].b);
				}
			}
			sort(g+1,g+hh+1);
			int uu=z-n/2;
			for(int i=1;i<=uu;i++)s-=g[i];
		}
		printf("%d\n",s);
	}
	return 0;
}
