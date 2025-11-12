#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w,bel;
}e[1100005];
struct vill{
	long long c, a[10005];
}v[15];
long long ufs[1100][10005], ans[1100];
long long find(long long t, long long x){
	if(ufs[t][x]==x){
		return x;
	}else ufs[t][x]=find(t,ufs[t][x]);
	return ufs[t][x];
}
void uni(long long t, long long x, long long y, long long w){
	long long u=find(t,ufs[t][x]), v=find(t,ufs[t][y]);
	if(u!=v){
		ufs[t][u]=v;
		ans[t]+=w;
	}
}bool cmp(edge lh, edge rh){
	return lh.w<rh.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w", stdout);
	ios::sync_with_stdio(0);
	long long n,m,k;
	cin >> n >> m >> k;
	for(long long i=1;i<=m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].bel=-1;
	}
	for(long long i=1;i<=k+n;i++){
		for(long long j=0;j<(1<<k);j++){
			ufs[j][i]=i;
		}
	}//cout << "ASSERT";
	for(long long i=1;i<=k;i++){
		cin >> v[i].c;
		for(long long j=1;j<=n;j++){
			cin >> v[i].a[j];
		} 
	}//cout << "ASSERT";
	for(long long i=0;i<(1<<k);i++){
		ans[i]=0;
		for(long long j=1;j<=k;j++){
			if(i&((1<<j)>>1)){
				ans[i]+=v[j].c;
			}
		}
	}long long r=m;
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			e[++r].w=v[i].a[j];
			e[r].u=i+n;
			e[r].v=j;
			e[r].bel=((1<<i)>>1);
		}
	}//cout << "ASSERT";
	sort(e+1, e+1+r, cmp);
	for(long long i=1;i<=r;i++){
		for(long long j=0;j<(1<<k);j++){
			if(e[i].bel==-1||(j&e[i].bel)){
				uni(j,e[i].u,e[i].v,e[i].w);
			}
		}
	}long long answ=LONG_LONG_MAX;
	for(long long i=0;i<(1<<k);i++){
		answ=min(answ, ans[i]);
		//cout << i << ":" << ans[i] << "\n";
	}cout << answ;
} 
