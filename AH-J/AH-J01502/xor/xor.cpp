#include "iostream"
#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
int n,k,a[500005],b[500005],tot=0,ans=1;
vector<int> v[5000005];
struct Node {
	int l,r;
}c[500005];
bool operator <(const Node &x,const Node &y){
	if (x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
int ll (int p,int q){
	int l=0,r=v[p].size()-1;
	while (l<=r){
		int mid; mid=l+r; mid>>=1;
		if (mid<q) l=mid+1;
		else r=mid-1;
	}
	return r;
}
//~ int lll (int s,int q){
	//~ int l=s,r=tot;
	//~ while (l<=r){
		//~ int mid; mid=l+r; mid>>=1;
		//~ if (mid<=q) l=mid+1;
		//~ else r=mid-1;
	//~ }
	//~ return r;
//~ }
void dfs (int step,int sum){
	ans=max(ans,sum);
	for (int i=step+1;i<=tot;i++){
		if (c[i].l>c[step].r) dfs (i,sum+1);
	}
}
int main(){
	//~ freopen ("xor.in","r",stdin);
	//~ freopen ("xor.out","w",stdout);
	scanf ("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf ("%d",&a[i]);
		b[i]=a[i]^b[i-1];
		v[b[i]].push_back(i);
	}
	for (int i=0;i<n;i++){
		if (v[k^b[i]].size()==0) continue;
		if (v[k^b[i]][v[k^b[i]].size()-1]<i+1) continue;
		int x;
		x=ll(k^b[i],i+1);
		//~ if (tot==0 || i+1>c[tot].r){
		c[++tot].l=i+1; c[tot].r=v[k^b[i]][x];
		//~ }
	}
	//~ sort (c+1,c+1+tot);
	if (tot==0){
		puts("0");
		return 0;
	}
	dfs (1,1);
	printf ("%d\n",ans);
	return 0;
}
