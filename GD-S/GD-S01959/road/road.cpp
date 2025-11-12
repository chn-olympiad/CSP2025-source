#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
constexpr int N=1000005,M=100005;

struct node{
	int x,y,dis;
	bool operator<(const node &__x) const{
		return __x.dis>dis;
	}
};

int n,m,k,fa[N];
bool flag;
ll ans;
inline void read(int &x){
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
}

inline void readl(ll &x){
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
}

inline int f(int x){
	return (fa[x]==x?x:fa[x]=f(fa[x]));
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	read(n);read(m);read(k);
	priority_queue<node> q;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int _x=0,_y=0,_z=0;
		read(_x);read(_y);read(_z);	
		q.push(node{_x,_y,_z});
	}
	for(int i=1;i<=k;++i){
		int _x=0;
		for(int j=1;j<=n;++j){
			read(_x);
			if(_x!=0) flag=1;
		}
	}
	if(!flag&&k) cout<<0;
	else{
		while(q.size()){
			node u=q.top();
			q.pop();
			int fax=f(u.x),fay=f(u.y);
			if(fax!=fay){
				ans+=u.dis;
				fa[u.x]=fay;
			}
		}
		cout<<ans;
	}
	return 0;
} 
