#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
	int x,y;
	long long z;
	inline bool operator<(const node &A)const{
		if (z!=A.z) return z<A.z;
		if (x!=A.x) return x<A.x;
		return y<A.y;
	}
};
int n,m,k,f[N];
int c[15][N],tot[15];
long long mi[15];
set<node> s;
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void Kru(){
	int cnt=0;long long ans=0;
	while (!s.empty()&&cnt<n-1){
		node t=*s.begin();
		s.erase(s.begin());
		int x=t.x,y=t.y;
		long long w=t.z;
		int xx=find(x),yy=find(y);
		if (xx!=yy){
			f[xx]=yy;
			ans+=w;
			++cnt;
			if (x>n){
				mi[x-n]=w;
				if (++tot[x-n]==1){
					--cnt;
					for (int i=1;i<=n;i++)
						if (i!=y)
							s.erase({x,i,c[x-n][i]+c[x-n][0]});
					for (int i=1;i<=n;i++)
						if (i!=y)
							s.insert({x,i,c[x-n][i]});
				}
			}
		}
	}
	for (int i=1;i<=k;i++)
		if (tot[i]==1)
			ans-=mi[i];
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n+k;i++) f[i]=i;
	for (int i=0;i<m;i++){
		int x,y;long long z;
		scanf("%d%d%lld",&x,&y,&z);
		s.insert({x,y,z});
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for (int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			s.insert({i+n,j,c[i][j]+c[i][0]});
		}
	}
	Kru();
	return 0;
}
