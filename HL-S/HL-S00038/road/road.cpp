#include<bits/stdc++.h> 
using namespace std;
int n,m,K,qi[10004],ee,f[10004],cnt,xs,ys,va[13],cntt[108];
long long as=99999999999999999,ls;
struct bb{
	int x;
	int y;
	long long vs;
} b[2000006],c[12][10004],awa,dk[12][100004];
bool cmp(bb ba,bb bc){
	return ba.vs<bc.vs;
}
int fd(int d){
	if (f[d]==d) return d;
	return f[d]=fd(f[d]);
}
void dfs(int d,long long ass,int ii){
	if (d>K){
		cnt=0;
		for (int i=1;i<=n+K;i++) f[i]=i;
		for (int i=1;i<=cntt[d-1];i++){
			//cout<<dk[d-1][i].vs<<endl;
			if (cnt==n+ii-1) break;
			xs=fd(dk[d-1][i].x);
			ys=fd(dk[d-1][i].y);
			if (xs!=ys){
				f[xs]=ys;
				cnt++;
				ass+=dk[d-1][i].vs;
			}
		}	
		as=min(as,ass);
	}
	else{
		cntt[d]=cntt[d-1];
		for (int j=1;j<=cntt[d-1];j++) dk[d][j]=dk[d-1][j];
		dfs(d+1,ass,ii);
		int l=1;
		int r=1;
		cntt[d]=0;
		while(l<=cntt[d-1]&&r<=n){
			cntt[d]++;
			if (dk[d-1][l].vs<c[d][r].vs) dk[d][cntt[d]]=dk[d-1][l],l++;
			else dk[d][cntt[d]]=c[d][r],r++;
		}
		for (l;l<=cntt[d-1];l++){
			cntt[d]++;
			dk[d][cntt[d]]=dk[d-1][l];
		}
		for (r;r<=n;r++){
			cntt[d]++;
			dk[d][cntt[d]]=c[d][r];
		}
		dfs(d+1,ass+va[d],ii+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for (int i=1;i<=m;i++){
		scanf("%d%d%lld",&b[i].x,&b[i].y,&b[i].vs);
	}
	for (int i=1;i<=n;i++) f[i]=i;
	sort(b+1,b+1+m,cmp);
	for (int i=1;i<=m;i++){
		if (cnt==n-1) break;
		xs=fd(b[i].x);
		ys=fd(b[i].y);
		if (xs!=ys){
			cnt++;
			f[xs]=ys;
			cntt[0]++;
			dk[0][cntt[0]]=b[i];
		}
	}
	for (int i=1;i<=K;i++){
		cin>>va[i];
		for (int j=1;j<=n;j++){
			scanf("%lld",&ls);
			awa.x=i+n;
			awa.y=j;
			awa.vs=ls;
			c[i][j]=awa;
		}
		sort(c[i]+1,c[i]+1+n,cmp);
	}
	dfs(1,0,0);
	cout<<as;
	return 0;
}
