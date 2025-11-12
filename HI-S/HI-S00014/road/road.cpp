#include<bits/stdc++.h>
#define float double
#define AC return 0
#define int long long
using namespace std;
long long n,m,k,c[20],mn,hr[20][10005],hx;
bool bl[20];
struct wh{
	int u,v,w;
}f[2000005],s[2000005];
bool cmp(wh x,wh y) {
	return x.w<y.w;
}
long long h(int asd) {
	bool bll[10005]={};
	int ans=0;
	int p=n+asd;
	sort(f+1,f+m+1,cmp);
	for(int i=1;i<=m&&p;i++) {
		if(!bll[f[i].u]||!bll[f[i].v]) {
			ans+=f[i].w;
			if(!bll[f[i].u]) p--,bll[f[i].u]=1;
			if(!bll[f[i].v]) p--,bll[f[i].v]=1;
		}
	}
	return ans;
}
signed main(void) {

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>f[i].u>>f[i].v>>f[i].w;
	for(int i=1;i<=m;i++) s[i].u=f[i].u,s[i].v=f[i].v,s[i].w=f[i].w;
	long long h0=h(0);
	//cout<<h0<<endl;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>hr[i][j];
			f[m+j].u=n+i;
			f[m+j].v=j;
			f[m+j].w=hr[i][j];
		}
		m+=n;
		mn=h(1)+c[i];
		//for(int k=1;k<=m;k++) cout<<f[k].u<<' '<<f[k].v<<' '<<f[k].w<<endl;
		m-=n;
		if(mn<h0) bl[i]=1;
		//cout<<i<<':'<<mn<<endl;
		for(int i=1;i<=m+n;i++) f[i].u=s[i].u,f[i].v=s[i].v,f[i].w=s[i].w;
	}
	mn=0;
	for(int i=1;i<=k;i++) if(bl[i]) {
		for(int j=1;j<=n;j++) {
			m++;
			f[m].u=n+i;
			f[m].v=j;
			f[m].w=hr[i][j];
		}
		hx++;
		mn+=c[i];
	}
	//for(int k=1;k<=m;k++) cout<<f[k].u<<' '<<f[k].v<<' '<<f[k].w<<endl;
	//cout<<mn<<' '<<hx<<endl;
	cout<<mn+h(hx);
	AC;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
