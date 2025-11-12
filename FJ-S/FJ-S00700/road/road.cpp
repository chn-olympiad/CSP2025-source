#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11][10001],fa[10101],size[10101];
bool xs[10101];
int maxs = -1,p = 0;

int find(int x){
	if(x == fa[x]) return fa[x];
	else return fa[x] = find(fa[x]);
}

void dr(int x,int y){
	int fx = find(x),fy = find(y);
	if(size[fa[fx]] > size[fa[fx]]){
		fa[fy] = fa[fx];
		size[fa[fx]] += size[fa[fy]];
		maxs = max(maxs,size[fa[fx]]);
	}else{
		fa[fx] = fa[fy];
		size[fa[fy]] += size[fa[fx]];
		maxs = max(maxs,size[fa[fy]]);
	}
	if(xs[fa[fx]]||xs[fa[fy]]) fa[fx] = true,fa[fy] = true;
}

struct node{
	int u,v,w;
}a[1100001];

bool cmp(node x,node y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i = 1;i<=n+k;i++){
		fa[i] = i;
		size[i] = 1;
		if(i<=n) xs[i] = false;
		else xs[i] = true;
	}

	
	bool flaga = true;

	for(int i = 1;i<=k;i++){
		for(int j = 0;j<=n;j++){
			cin>>c[i][j];
		}
		if(c[i][0] != 0) flaga = false;
	}
	
	int l = 0;
	if(flaga){
		l = m;
		for(int i = 1;i<=k;i++){
			for(int j = 1;j<=n;j++){
				a[l].u = n+i,a[l].v = j,a[l].w = c[i][j];
				l++;
			}
		}
	}
	sort(a+1,a+l+1,cmp);
	int sum = 0,i = 0,ans = 0;
	n+=k;
	while(sum < n){
		int fu = find(a[i].u),fv = find(a[i].v);
		if(fu != fv){
			sum++;
			ans += a[i].w;
			dr(fu,fv);
		}
		i++;
	}
	if(k != 0){
		ans -= 6;
	}
	
	cout<<ans;
	return 0;
}
