#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int base;
	vector<int>to;
	vector<int>tobase;
	int lto;
	bool must_visit,is_visit;
}a[10100];
struct Road{
	int u,v,w;
}r[1000100];
bool cmp(Road A,Road B){
	if(A.u!=B.u){
		return A.u<B.u;
	}
	if(A.v!=B.v){
		return A.v<B.v;
	}
	return A.w<B.w;
}
int w;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n+k;i++){
		a[i].base=0;
		a[i].lto=0;
		a[i].must_visit=true;
		a[i].is_visit=false;
	}
	for(int i=n+1;i<=n+k;i++){
		a[i].must_visit=false;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(r[i].u!=r[i-1].u&&r[i].v!=r[i-1].v){
			a[r[i].u].to.push_back(r[i].v);
			a[r[i].v].to.push_back(r[i].u);
			a[r[i].u].tobase.push_back(r[i].w);
			a[r[i].v].tobase.push_back(r[i].w);
			a[r[i].u].lto++;
			a[r[i].v].lto++;
			ans+=r[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[n+i].base);
		ans+=a[n+i].base;
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			a[n+i].to.push_back(j);
			a[j].to.push_back(n+i);
			a[n+i].tobase.push_back(w);
			a[j].tobase.push_back(w);
			a[n+i].lto++;
			a[j].lto++;
			ans+=w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
