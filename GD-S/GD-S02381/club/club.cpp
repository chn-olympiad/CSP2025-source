# include<cmath>
# include<cstdio>
# include<cstring>
# include<iostream>
# include<algorithm>
# define V inline void
# define ll long long
const int N=2e5+10;
using namespace std;
int T;
int n;
int siz[4];
struct SO{
	int x,id;
}b[4],heap[4][N];
struct Node{
	int dm[4];
	int nw[4];
}a[N];
bool cmp(SO u,SO v) {
	return u.x>v.x;
}
V push(int op,int x,int y) {
	//op,x差值，y那个人
	heap[op][++siz[op]]=(SO){x,y};
	int s=siz[op],p;
	while(s>1) {
		p=s/2;
		if(heap[op][p].x<=heap[op][s].x) break;
		swap(heap[op][p],heap[op][s]);
		s=p;
	}
	return ;
}
V pop(int op) {
	heap[op][1]=heap[op][siz[op]--];
	int s,p=1;
	while(p*2<=siz[op]) {
		s=p*2;
		if(heap[op][s+1].x<heap[op][s].x) s++;
		if(heap[op][p].x<=heap[op][s].x) break;
		swap(heap[op][p],heap[op][s]);
		p=s;
	}
	return ;
}
V csh() {
	memset(a,0,sizeof(a));
	memset(heap,0,sizeof(heap));
	memset(siz,0,sizeof(siz));
	return ; 
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		csh();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) scanf("%d",&a[i].dm[j]);
			for(int j=1;j<=3;j++) b[j]=(SO){a[i].dm[j],j};
			sort(b+1,b+4,cmp);
			for(int j=1;j<=3;j++) a[i].nw[j]=b[j].id;
		}
		//a[i].nw[0]此时a[i]被分配到了哪里(第几大)。 
		ll ans=0;
		for(int i=1;i<=n;i++) {
			//维护小根堆 
			a[i].nw[0]=1;
			int op=a[i].nw[a[i].nw[0]],op2=a[i].nw[a[i].nw[0]+1];
			push(op,a[i].dm[op]-a[i].dm[op2],i);
			ans+=a[i].dm[op];
			for(int j=1;j<=3;j++) {
				if(siz[j]>n/2) {
					int x=heap[op][1].id;
					ans-=a[x].dm[op];
					a[x].nw[0]++;
					int opp=a[x].nw[a[x].nw[0]],opp2=a[x].nw[a[x].nw[0]+1];
					//不存在二次搬运 
					ans+=a[x].dm[opp];
					push(opp,a[x].dm[opp]-a[x].dm[opp2],x);
					pop(op);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
