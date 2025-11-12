#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1e5+111;
struct st{
	int x,y,w;
};
int n,m,k,f[N],d1[51];
bool d[51];
vector<st> v;

bool cmp(st x,st y){
	return x.w < y.w;
}

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y) f[x]=y;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);

	for(int i=1;i<=n+k;i++) f[i]=i;
		
	for(int i=1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		v.push_back({x,y,w});
	}
	for(int i=1;i<=k;i++){
		int c,w;
		scanf("%d",&c);
		d1[i]=c;
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			v.push_back({n+i,j,w+c});
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	
	long long ans=0,sumN=0;
	for(int i=0;i<v.size();i++){
		int x=v[i].x,y=v[i].y,w=v[i].w;
		if(find(x)==find(y)) continue;
		add(x,y);
		ans+=w;
		
		if(x>n && d[x-n]==0){
			d[x-n]=1;
			ans-=d1[x-n];
		}
		if(y>n && d[y-n]==0){
			d[y-n]=1;
			ans-=d1[y-n];
		}
		
		if(x<=n && y<=n) sumN++;
		if(sumN== n-1) break;
		bool flag=1;
		for(int i=2;i<=n;i++){
			if(find(1)!=find(i)){
				flag=0;
				break;
			}
		}
		if(flag==1) break;
	}
	printf("%lld",ans);

	return 0;
}

