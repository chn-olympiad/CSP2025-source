#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f;
int n,m,k,fa[10005],tmp,vil[15][10005],c[15],tot,ans,u,v,w,f_u,f_v,anss,mn,cnt,flag[15],res,num[15],ab[15];
bool vis[15];
struct node {
	int u,v,w,bl;
}a[1100005];
int find_f (int u) {
	return fa[u]==u?u:find_f(fa[u]);
}
bool cmp (node x,node y) {
	return x.w<y.w;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//clock_t start=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
		q.push({a[i].w,i});
		a[i].bl=0;
	}
	vis[0]=true;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		mn=inf;
		for(int j=1;j<=n;j++) {
			cin>>vil[i][j];
			a[m+n*(i-1)+j].u=n+i;
			a[m+n*(i-1)+j].v=j;
			a[m+n*(i-1)+j].w=vil[i][j];
			a[m+n*(i-1)+j].bl=i;
			if(mn>vil[i][j]) {
				mn=vil[i][j];
				flag[i]=j;
			}
		}
		q.push({mn+c[i],m+n*(i-1)+flag[i]});
	}
	cnt=n-1;
	for(int i=1;i<=n+k;i++) {
		fa[i]=i;
	}
	while(!q.empty()) {
		pair<int,int> tmp=q.top();
		q.pop();
		res=tmp.second;
		u=a[res].u;
		v=a[res].v;
		w=a[res].w;
		f_u=find_f(u);
		f_v=find_f(v);
		if(f_u==f_v) {
			continue;
		}
		if(!vis[a[res].bl]) {
			cnt++;
			ab[a[res].bl]=tmp.first;
			//cout<<1<<endl;
			vis[a[res].bl]=true;
			for(int j=1;j<=n;j++) {
				if(flag[a[res].bl]!=j) {
					q.push({vil[a[res].bl][j],m+n*(a[res].bl-1)+j});
				}
			}
		}
		else {
			if(u>n) {
				num[u-n]++;
			}
		}
		tot++;
		//cout<<tot<<" "<<cnt<<" ";
		//cout<<tmp.first<<endl;
		fa[f_u]=f_v;
		ans+=tmp.first;
		if(tot>=cnt) {
			break;
		}
	}
	for(int i=1;i<=k;i++) {
		if(vis[i]&&!num[i]) {
			ans-=ab[i];
		}
		//cout<<num[i]<<" "<<vis[i]<<endl;
	}
	cout<<ans;
	//clock_t endd=clock();
	//cout<<endl<<(endd-start)/1000;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 4 7
2 3 6
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 0
*/
