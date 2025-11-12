#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define REPG(i,g,x) for(int i=g.head[x];~i;i=g.edge[i].nxt)
#define LL long long

template<class T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
template<class T>
inline void write(T x){
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}

const int N=1e5+5;
int T;

int n;
int a[N][3];vector<array<int,2> > b[N];
int c[N];
priority_queue<array<int,2> > buc[3];
void work(){
	read(n);
	rep(i,1,n) {
		b[i].clear();
		rep(j,0,2) read(a[i][j]),b[i].push_back({a[i][j],j});
		sort(b[i].begin(),b[i].end());
		c[i]=b[i][2][0]-b[i][1][0];
	}
	rep(j,0,2) while(!buc[j].empty()) buc[j].pop();
	int ans=0;
	//bool fg=0;
	rep(i,1,n){
		int val=b[i][2][0],j=b[i][2][1];
		ans+=val;
		buc[j].push({-c[i],i});
		if((int)buc[j].size()>n/2) {
			auto u=buc[j].top();
			buc[j].pop();
			ans+=u[0];
			//fg=1;
		}
	}
	// if(fg) cerr<<"***"<<endl;
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;read(T);
	while(T--) work();	

	return 0;
}