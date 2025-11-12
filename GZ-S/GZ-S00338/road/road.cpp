//GZ-S00338 毕节梁才学校 王艺杰
#include <bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}a[200010];
bool v[1010];
int cnt[1010];
int f[10010];
int n,m,k;
int find(int x){
	if (f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
}
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("rosd.out","w",stdout);
	cin >> n >> m >>k;
	for (int i=1; i<=n+n*k; i++) f[i]=i;
	for (int i=1; i<=m; i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	} 
	for (int i=1; i<=k; i++){
		cin >> cnt[i];
		for (int j=1; j<=n;j++){
			int x;
			scanf("%d",&x);
			a[n+(i-1)*10+j].u=i+n,a[n+(i-1)*10+j].v=j,a[n+(i-1)*10+j].w=x;
		}
	}
	sort(a+1,a+k*n+1+n,cmp);
	long long ans=0;
	for (int i=1; i<=n+k*n; i++){
		int gu=find(a[i].u),gv=find(a[i].v);
		if (gu!=gv){
			f[gu]=gv;
			ans+=a[i].w;
			if(a[i].u>n){
				v[a[i].u-n]=1;
			}
		}
	}
	for (int i=1; i<=k; i++){
		if (v[i]){
			ans+=cnt[i];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
