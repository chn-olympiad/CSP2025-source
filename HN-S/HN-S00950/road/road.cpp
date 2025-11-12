#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,k,ans=0;
struct Edge{
	int v,u,w;
	Edge(int v,int u,int w):v(v),u(u),w(w){}
};
vector<Edge>s;
vector<int>a[15];
int c[15];

int fa[N];

bool cmp(const Edge x,const Edge y){
	return x.w<y.w;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
bool merge(int x,int y){
	int rx=get(x),ry=get(y);
	if(rx==ry){
		return false;
	}else{
		fa[rx]==ry;
		return true;
	}
}
int ro[1005][1005];
bool to[15];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s.push_back(Edge(a,b,c));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int p;
		for(int j=1;j<=n;j++){
			cin>>p;
			a[i].push_back(p);
		}
//		for(int j=0;j<n;j++){
//			for(int t=j+1;t<n;t++){
//				s.push_back(Edge(j+1,t+1,a[i][j]+a[i][t],i));
//			}
//		}
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(cnt==n-1)break;
		if(!merge(s[i].v,s[i].u))continue;
		ans+=s[i].w;
		cnt++;
	}
	cout<<ans;
}

