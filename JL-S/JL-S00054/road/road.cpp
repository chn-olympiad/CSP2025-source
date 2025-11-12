#include<bits/stdc++.h>
#define int long long
#define fors(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+567;
int n,m,k,ans=LLONG_MAX;
int c[15][N],f[N];
struct edge{
	int x;
	int y;
	int l;
};
vector<edge>g;
bool cmp(edge x,edge y){
	return x.l<y.l;
}
int find(int x){
	if(f[x]==x)return x; 
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	f[xx]=yy;
}
void krudfs(vector<edge>v,int u,int h,int tot){
	if(h==0){
		int cnt=tot;
		sort(v.begin(),v.end(),cmp);
		fors(i,1,n+k){
			f[i]=i;
		}
		for(edge w:v){
			if(find(w.x)!=find(w.y)){
				merge(w.x,w.y);
				cnt+=w.l;
			}
		}
		ans=min(ans,cnt);
		//cout<<cnt<<'\n';
	}
	if(u==k)return;
	krudfs(v,u+1,1,tot);
	fors(i,1,n){
		v.push_back({u+1+n,i,c[u+1][i]});
	}
	krudfs(v,u+1,0,tot+c[u+1][0]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	fors(i,1,m){
		int x,y,l;
		cin>>x>>y>>l;
		g.push_back({x,y,l});
	}
	fors(i,1,k){
		cin>>c[i][0];
		fors(j,1,n){
			int l;
			cin>>l;
			c[i][j]=l;
		}
	}
	krudfs(g,0,0,0);
	cout<<ans;
	return 0;
}
