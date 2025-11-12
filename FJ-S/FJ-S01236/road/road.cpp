#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const long long N = 1e6+10;
struct node{
	long long u, v, w;
}tu[N];
long long n,m,k,bing[N],t_k,vis[N];
bool cmp(node x,node y){
	return x.w <= y.w;
}
long long find(long long x){
	if(x == bing[x]){
		return x;
	}
	return find(bing[x]);
}
void query(long long x,long long y){
	long long xx = find(x);
	long long yy = find(y);
	bing[xx] = bing[yy];
	return;
}
int main(){
	FILE("road");
	cin >> n >> m >> k;
	for(long long i=1;i<=m;i++){
		long long tmp1,tmp2,tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		tu[++t_k].u = tmp1;
		tu[t_k].v = tmp2;
		tu[t_k].w = tmp3; 
	}
	for(long long i=1;i<=k;i++){
		cin >> vis[i];
		for(long long j=1;j<=n;j++){
			long long tmp;
			cin >> tmp;
			tu[++t_k].u = n+i;
			tu[t_k].v = j;
			tu[t_k].w = tmp+vis[i];
		}
	}
	sort(tu+1,tu+t_k+1,cmp);
	for(long long i=1;i<=n+k;i++){
		bing[i] = i;
	}
	long long ans=0;
	for(long long i=1;i<=t_k;i++){
		if(find(tu[i].u) != find(tu[i].v)){
			ans += tu[i].w;
			query(tu[i].u,tu[i].v);
			if(tu[i].u > n && vis[tu[i].u-n] != 0){
				for(long long j=1;j<=t_k;j++){
					if(tu[j].u == tu[i].u){
						tu[j].w-=vis[tu[i].u-n];
					}
				}
				sort(tu+1,tu+t_k+1,cmp);
				vis[tu[i].u-n] = 0;
				i=1;
			}
			long long xx = find(1),flag=1;
			for(long long i=1;i<=n;i++){
				if(find(i) != xx){
					flag=0;
				}
			}
			if(flag){
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

