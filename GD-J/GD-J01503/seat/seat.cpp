#include <cstdio>
#include <algorithm>
int n,m;
struct node{
	int v,id;
	bool operator<(const node &r)const{
		return v>r.v;
	}
}a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].v),a[i].id=i;
	std::sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){
			int x=0,y=0;
			if(i%n==0){
				y=i/n;
				if(y&1) printf("%d %d",y,n);
				else printf("%d 1",y);
			}else{
				y=i/n;
				x=i%n;
				y++;
				if(y&1) printf("%d %d",y,x);
				else printf("%d %d",y,n-x+1);
			}
			break;
		}
	return 0;
}
