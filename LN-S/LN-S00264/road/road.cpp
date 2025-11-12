#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;
int nw[15][10005];
int cs[15],cnt[15];
int f[10050];

struct Edge{
	int u,v,c;
}e[110005];

bool cmp(Edge x,Edge y){
	return x.c<y.c;
}

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++) cin >> e[i].u >> e[i].v >> e[i].c;
	int p=m;
	for(int i=1;i<=k;i++){
		cin >> cs[i];
		for(int j=1;j<=n;j++){
			cin >> e[++p].c;
			e[p].u=n+i,e[p].v=j;
		}
	}
	sort(e+1,e+p+1,cmp);
	for(int i=1;i<=n+k;i++) f[i]=i;
	int cnnt=0,ans=0;
	vector<int>a[k];
	for(int i=1;i<=k;i++) a[i].clear();
	for(int i=1;i<=p;i++){
		int u=e[i].u,v=e[i].v,c=e[i].c;
		if(find(u)!=find(v)){
			f[find(u)]=find(v),cnnt++;
			if(u>n){
				cnt[u-n]++;
				a[u-n].push_back(c);
			}
			else ans+=c;
		}
		if(cnnt>=n+k-1) break;
	}
	for(int i=1;i<=k;i++){
		if(cnt[i]>=2){
			ans+=cs[i];
			for(int j=0;j<a[i].size();j++) ans+=a[i][j];
		}
	}
	cout << ans;
	return 0;
}
