#include <bits/stdc++.h>
using namespace std;
struct edge{
	int a,b,len;
};
bool cmp(edge a,edge b){
	return a.len<b.len;
}
int n,m,k,fa[10005],mp[15][10005];
bool pd[15][10005];
vector<edge> b;
int fi(int x){
	return fa[x]==x?x:fa[x]=fi(fa[x]);
}
long long kl(){
	sort(b.begin(),b.end(),cmp);
	int num=1;
	long long sum=0;
	for(int i=0;i<b.size();i++){
		int xl=fi(b[i].a),yl=fi(b[i].b);
		if(xl!=yl){
			fa[xl]=yl;
			num++;
			int Min=2e9,a1,b1,j1;
			for(int j=1;j<=k;j++){
				if((!pd[j][b[i].a]?mp[j][b[i].a]:0)+(!pd[j][b[i].b]?mp[j][b[i].b]:0)<Min){
					Min=(!pd[j][b[i].a]?mp[j][b[i].a]:0)+(!pd[j][b[i].b]?mp[j][b[i].b]:0);
					a1=b[i].a;
					b1=b[i].b;
					j1=j;
				}
			}
			if(Min<b[i].len){
				pd[j1][a1]=pd[j1][b1]=true;
				sum+=Min;
			}
			else{
				sum+=b[i].len;
			}
		}
		if(num>=n){
			return sum;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,bb,len;
		cin>>a>>bb>>len;
		b.push_back({a,bb,len});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int s;
			cin>>s;
			mp[i][j]=s;
		}
	}
	cout<<kl();
	return 0;
}
//48
