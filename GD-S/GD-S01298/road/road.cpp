#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#define int long long
using namespace std;

void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
int fa[20010],siz[20010];
int getf(int k){
	return fa[k]==k?k:(fa[k]=getf(fa[k]));
}
int us[1100010],vs[1100010],ws[1100010];
int n,m,k,prv[1100010],res=4e18;
int exts[11][10010],c[11];
bool cmp(int x,int y){
	return ws[x]<ws[y];
}
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=1;
	}
}
bool merge(int u,int v){
	u=getf(u),v=getf(v);
	if(u==v){
		return 0;
	}
	if(siz[u]>siz[v]){
		swap(u,v);
	}
	fa[u]=v;
	siz[v]+=siz[u];
	return 1;
}
void solve(int p,const vector<int>& id,int sum){
	if(p==k+1){
		return;
	}else{
		solve(p+1,id,sum);
		init();
		vector<int> nw;
		int cur=0,ptr1=0,ptr2=1;
		while(1){
			if(ptr1==id.size() || ptr2==n+1){
				break;
			}
			if(ws[id[ptr1]]<ws[exts[p][ptr2]]){
				if(merge(us[id[ptr1]],vs[id[ptr1]])){
					nw.push_back(id[ptr1]);
					cur+=ws[id[ptr1]];
				}
				ptr1++;
			}else{
				if(merge(us[exts[p][ptr2]],vs[exts[p][ptr2]])){
					nw.push_back(exts[p][ptr2]);
					cur+=ws[exts[p][ptr2]];
				}
				ptr2++;
			} 
		}
		while(ptr1!=id.size()){
			if(merge(us[id[ptr1]],vs[id[ptr1]])){
				nw.push_back(id[ptr1]);
				cur+=ws[id[ptr1]];
			}
			ptr1++;
		}
		while(ptr2!=n+1){
			if(merge(us[exts[p][ptr2]],vs[exts[p][ptr2]])){
				nw.push_back(exts[p][ptr2]);
				cur+=ws[exts[p][ptr2]];
			}
			ptr2++;
		}
		res=min(res,sum+c[p]+cur);
		solve(p+1,nw,sum+c[p]);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++){
		read(us[i+n*k]);
		read(vs[i+n*k]);
		read(ws[i+n*k]);
		prv[i]=i+n*k;
	}
	sort(prv+1,prv+m+1,cmp);
	init();
	int cur=0;
	vector<int> id;
	for(int i=1;i<=m;i++){
		if(merge(us[prv[i]],vs[prv[i]])){
			id.push_back(prv[i]);
			cur+=ws[prv[i]];
		}
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			us[(i-1)*n+j]=n+i;
			vs[(i-1)*n+j]=j;
			read(ws[(i-1)*n+j]);
			exts[i][j]=(i-1)*n+j;
		}
		sort(exts[i]+1,exts[i]+n+1,cmp);
	}
	res=cur;
	solve(1,id,0);
	printf("%lld",res);
	return 0;
}
