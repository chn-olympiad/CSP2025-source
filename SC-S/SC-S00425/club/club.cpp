#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,m;
long long ans;
struct node{ long long people,val,id; };
vector<node> a;
bool cmp(node &x,node &y){
	if(x.val==y.val) return x.id<y.id;
	else return x.val>y.val; 
}
bool vis[N];int cnt[5];
multiset<long long> nex[5];
long long maxx[N],midd[N];
long long find_midd(long long x,long long y,long long z){
	long long o=max({x,y,z});
	if(o==x) return max(y,z);
	if(o==y) return max(x,z);
	if(o==z) return max(x,y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);m=0;
		ans=0;a.clear();
		for(int i=1;i<=3;i++) cnt[i]=0,nex[i].clear(); 
		for(int i=1;i<=n;i++) vis[i]=false;
		for(long long i=1,sx,sy,sz;i<=n;i++){
			scanf("%lld%lld%lld",&sx,&sy,&sz);
			a.push_back(node{i,sx,1});
			a.push_back(node{i,sy,2});
			a.push_back(node{i,sz,3});
			maxx[i]=max({sx,sy,sz});
			midd[i]=find_midd(sx,sy,sz);
		}
		sort(a.begin(),a.end(),cmp);
		for(int i=0;i<3*n;i++){
			node now=a[i];int f=now.id,u=now.people;
			if(m==n) break;
			if(vis[u]) continue;
			if(cnt[f]<(n/2)){ 
				cnt[f]++;ans+=now.val;vis[u]=true;m++;
				nex[f].insert(midd[u]-maxx[u]);
			}else{
				long long d1=midd[u]-maxx[u];
				long long d2=*(--nex[f].end());
				if(d1>=d2) continue;
				else{
					vis[u]=true;ans+=now.val+d2;m++;
					nex[f].erase((--nex[f].end()));
					nex[f].insert(midd[u]-maxx[u]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}