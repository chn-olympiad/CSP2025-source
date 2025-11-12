#include<bits/stdc++.h>
using namespace std;
struct edge{
	int st,en,poin;
} a[2000005];
struct node{
	int en;
	int poin;
};
vector<node> mapp[10085];
bool cmp(edge x,edge y){return x.poin<y.poin;}
int bcj[100005],cit[10][100005];
int fnd(int x){
	if(bcj[x]==x) return x;
	bcj[x]=fnd(bcj[x]);
	return bcj[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >>m>>k;
	for(int i=1;i<=m;i++) cin >> a[i].st>>a[i].en>>a[i].poin;
	for(int z=1;z<=k;z++){
		cin >> cit[z][0];
		for(int j=1;j<=n;j++){
			cin >> cit[z][j];
			a[n+(z-1)*n+j].st=n+z;
			a[n+(z-1)*n+j].poin=cit[z][0]+cit[z][j];
			a[n+(z-1)*n+j].en=j;
		}
	}
	for(int i=1;i<=n+k;i++) bcj[i]=i;
	sort(a+1,a+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		int q=fnd(a[i].en),p=fnd(a[i].st);
		if(q!=p){
			mapp[a[i].en].push_back({a[i].st,(a[i].st>n?a[i].poin-cit[a[i].st-n][0]:a[i].poin)});
			mapp[a[i].st].push_back({a[i].en,(a[i].st>n?a[i].poin-cit[a[i].st-n][0]:a[i].poin)});
			bcj[p]=bcj[q];
		}
	}
	int s=0;
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<mapp[i].size();j++) s+=mapp[i][j].poin;
	}
	s/=2;
	for(int i=n+1;i<=n+k;i++){
		if(mapp[i].size()==1) s-=mapp[i][0].poin;
		else s+=cit[i-n][0];
	}
	cout << s;
}
