#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[110],f[1010];
long long ans;
int find(int x){
	return x==f[x]?x:find(f[x]);
}
struct node {
	int x,y,c;
}a[1010000];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].c);
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		int x=a[i].x,y=a[i].y;
		if(find(x)!=find(y)){
			f[x]=f[y];
			ans+=a[i].c;
		}
	}
	printf("%lld\n",ans);
}
