#include<bits/stdc++.h>

#define In(x) freopen(x,"r",stdin)
#define Out(x) freopen(x,"w",stdout)

using namespace std;

int n,p,t;

const int N=1e5+5;

int a[N][3],id[N][3];

vector<int> v[3];

inline bool cmp(int x,int y){
	return a[p][x]<a[p][y];
}

inline bool cmp2(int x,int y){
	return a[x][id[x][t]]-a[x][id[x][t-1]]>a[y][id[y][t]]-a[y][id[y][t-1]];
}

inline void Calc(){
	scanf("%d",&n);
	for(int i=0;i<=2;i++) v[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++) scanf("%d",&a[i][j]),id[i][j]=j;
		p=i,sort(id[i],id[i]+3,cmp);
	}
	for(int i=1;i<=n;i++){
		int now=id[i][2];
		v[now].push_back(i);
	}
	for(t=2;t>=1;t--) for(int i=0;i<=2;i++) if(v[i].size()>n/2){
		sort(v[i].begin(),v[i].end(),cmp2);
		while(v[i].size()>n/2){
			int now=v[i].back();v[i].pop_back();
			v[id[now][t-1]].push_back(now);
		}
		break;
	}
	int ans=0;
	for(int i=0;i<=2;i++) for(auto x:v[i]) ans+=a[x][i];
	printf("%d\n",ans);
}

signed main()
{
	In("club.in");Out("club.out");
	int T;scanf("%d",&T);
	while(T--) Calc();
	return 0;
}
