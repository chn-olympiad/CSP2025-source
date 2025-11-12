#include <bits/stdc++.h>
#define int long long
using namespace std;
struct ww{
	int a,b,c;
}v[1500005];
int n,m,k;
int fa[1000005];
int Call[1000005];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline bool cmp(ww l,ww r){
//	if(l.c==r.c)return (rand()&1);
	return l.c<r.c;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	cout<<"Flag"<<endl;
	for(int i=1;i<=n+k;i++)fa[i]=i;
//	cout<<"Flag"<<endl;
	for(int i=1;i<=m;i++){
		cin>>v[i].a>>v[i].b>>v[i].c;
	}
//	cout<<"Flag"<<endl;
	for(int i=1;i<=k;i++){
		int a;
		cin>>Call[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			++m;
			v[m]={n+i,j,a};
		}
	}
//	cout<<m<<endl;
	sort(v+1,v+m+1,cmp);
//	cout<<"Flag"<<endl;
	int sum=0,kuai=n+k;
	for(int i=1;i<=m&&kuai>=0;i++){
		int a=find(v[i].a),b=find(v[i].b);
		if(a==b)continue;
//		cout<<a<<' '<<b<<endl;
		fa[a]=b;
		if(a>=n){
			sum+=Call[a];
			Call[a]=0;
		}
		if(b>=n){
			sum+=Call[b];
			Call[a]=0;
		}
		kuai--;
		sum+=v[i].c;
	}
	cout<<sum;
	return 0;
}

