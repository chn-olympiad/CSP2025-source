#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1000005];
int co[10005];
	long long cnt=0;
struct ac {
	int uo,vo,wo;
} P[1000005];
int find(int x) {
	if(f[x]==x) {
		return x;
	} else {
		return f[x]=find(f[x]);
	}
}
int Union(int q,int w) {
	int qq=find(q);
	int ww=find(w);
	if(qq!=ww) {
		f[qq]=ww;
		return 1;
	} else {
		return 0;
	}
}
long long n,m,k;
bool cmp(ac x,ac y){
	return x.wo<y.wo;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>n>>m>>k;

	for(int i=1; i<=m; i++) {
		f[i]=i;
		int u,v,w;
		cin>>u>>v>>w;
		P[++cnt].uo=u;
		P[cnt].vo=v;
		P[cnt].wo=w;
	}

	int vv;
	for(int i=1; i<=k; i++) {
		cin>>co[i];
		for(int j=1; j<=n; j++) {
			cin>>vv;
			P[++cnt].uo=i;
		    P[cnt].vo=j;
		    P[cnt].wo=w;			
		}
	}
	
//	for(int i=1; i<=k; i++) {
//		for(int j=1; j<=n; j++) {
//			for(int r=1; r<=n; r++) {
//				d[j][r]=min(c[j][i]+c[i][r]-co[i],d[j][r]);
//			}
//
//		}
//	}

//	for(int i=1; i<=n; i++) {
//		for(int j=i; j<=n; j++) {
//			if(d[i][j]!=0) {
//				P[++cnt].uo=i;
//				P[cnt].vo=j;
//				P[cnt].wo=d[i][j];
//			}
//
//		}
//	}
//	for(int i=1;i<=cnt;i++){
//		cout<<P[i].uo<<" "<<P[i].vo<<" "<<P[i].wo<<endl;
//	}
	sort(P+1,P+1+cnt,cmp);
	long long sum1=0,sum2=0;
	for(int i=1;i<=cnt;i++){
		if(Union(P[i].uo,P[i].vo)){
			sum1++;sum2+=P[i].wo;
		}
	}
	cout<<sum2;
	return 0;
}
