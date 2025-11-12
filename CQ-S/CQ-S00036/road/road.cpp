#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define il inline
using namespace std;
namespace starlit{
	int n,m,k;
	const int maxm=2e6+5;
	const int maxn=1e4+5;
	const int maxk=15;
	struct edge{
		int l;
		int r;
		int c;
	};
	vector<edge> a,b;
	int c[maxk];
	int d[maxk][maxn];
	int v[maxk];
	int fa[maxn+maxk];
	int find(int x){
		if(x==fa[x]) return x;
		fa[x]=find(fa[x]);
		return fa[x];
	}
	bool cmp(edge x,edge y){
		return x.c<y.c;
	}
	signed main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a.push_back({x,y,z});
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			cout<<c[i]<<' ';
			for(int j=1;j<=n;j++){
				cin>>d[i][j];
			}
		}
		int g=0;
		int pok=pow(2,k);
		int mn=0x3f3f3f3f3f3f3f3f;
		while(g<pok){
			int dddd=g;
			for(int i=1;i<=n+k;i++) fa[i]=i;
			for(int i=1;i<=k;i++){
				v[i]=dddd%2;
				dddd>>=1;
			}
			b.clear();
			int ans=0;
			for(int i=1;i<=k;i++){
				if(v[i]!=0){
					ans+=c[i];
					for(int j=1;j<=n;j++){
						b.push_back({i+n,j,d[i][j]});
					}
				}
			}
			for(int i=0;i<m;i++){
				b.push_back(a[i]);
			}
			sort(b.begin(),b.end(),cmp);
//			cout<<ans<<"::\n";
			int h=0; 
			for(int i=0;i<b.size();i++){
				int x=b[i].l;
				int y=b[i].r;
				int fx=find(x),fy=find(y);
				if(fx!=fy){
//					cout<<fx<<' '<<fy<<'\n';
					fa[fy]=fa[x];
					ans+=b[i].c;
					if(ans>mn){
						break;
					}
//					cout<<h<<" : ";
//					cout<<b[i].l<<' '<<b[i].r<<' '<<b[i].c<<'\n'; 
					h++;
				}
			}
//			cout<<'\n';
			mn=min(mn,ans);
//			cout<<"----"<<g<<' '<<mn<<' '<<ans<<"\n\n\n";
//			system("pause");
			g++;
		}
		cout<<mn;
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	starlit::main();
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13


常数怎么这么大 
32pts~64pts?

 
*/
