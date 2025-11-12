#include<bits/stdc++.h>
using namespace std;
struct N {
	int x,y;
} a[100001],b[100001],c[100001];
int T,n,sum,e,f,g,x,y,z;
inline bool cmp(N a,N b){
	return a.y<b.y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		sum=x=y=z=0;
		scanf("%d",&n);
		for(int i=1;i<=n; ++i) {
			scanf("%d%d%d",&e,&f,&g);
			if(e>=f&&e>=g){
				if(f>g)a[++x]={e,f-e};
				else a[++x]={e,g-e};
				sum+=e;
			}else if(e<=f&&f>=g){
				if(e>g)b[++y]={f,e-f};
				else b[++y]={f,g-f};
				sum+=f;
			}else{
				if(e>f)c[++z]={g,e-f};
				else c[++z]={g,f-g};
				sum+=g;
			}
		}
		if(x>n/2){
			sort(a+1,a+x+1,cmp);
			for(int i=n/2+1;i<=x;++i)sum+=a[i].y;
		}
		if(y>n/2){
			sort(b+1,b+y+1,cmp);
			for(int i=n/2+1;i<=y;++i)sum+=b[i].y;
		}
		if(z>n/2){
			sort(c+1,c+z+1,cmp);
			for(int i=n/2+1;i<=z;++i)sum+=c[i].y;
		}
		printf("%d\n",sum);
	}
	return 0;
}
