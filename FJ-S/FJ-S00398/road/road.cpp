#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[15000];
long long ans;
struct road{int u,v;long long w;}r[2300000],r1[2300000];
struct city{long long co,a[12000];}c[20];
bool cmp(road x,road y){return x.w<y.w;}
long long fin(int z){
	long long a=0;
	int o,q=m*2,mi,ma,ci=0,fi=1;
	for (int i=0;i<m*2;i++) r1[i].u=r[i].u,r1[i].v=r[i].v,r1[i].w=r[i].w;
	for (int i=1;i<=n;i++) f[i]=0;
	for (int i=0;z>0;i++){
		if(z%2==1){
			a+=c[i].co;
			for (o=1;o<=n;o++) if(c[i].a[o]==0) break;
			if(o>n) o+=ci,ci++;
			for (int j=1;j<=n;j++){
				if(o!=j){
					r1[q].u=o,r1[q].v=j,r1[q].w=c[i].a[j],q++;
					r1[q].v=o,r1[q].u=j,r1[q].w=c[i].a[j],q++;
				}
			}
		}
		z/=2;
	}
	sort(r1,r1+q,cmp);
	for (int i=0;i<q;i++){
		if(f[r1[i].u]==0||f[r1[i].v]==0){
			if(f[r1[i].u]==0&&f[r1[i].v]==0) a+=r1[i].w,f[r1[i].u]=fi,f[r1[i].v]=fi,fi++;
			else a+=r1[i].w,f[r1[i].u]=max(f[r1[i].u],f[r1[i].v]),f[r1[i].v]=max(f[r1[i].u],f[r1[i].v]);
		}else if(f[r1[i].u]!=f[r1[i].v]){
			mi=min(f[r1[i].u],f[r1[i].v]),ma=max(f[r1[i].u],f[r1[i].v]);
			for (int j=1;j<=n+ci;j++) if(f[j]==mi) f[j]=ma;
			a+=r1[i].w;
		}
	}
	return a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i=0;i<m;i++){
		cin >> r[i].u >> r[i].v >> r[i].w;
		r[m+i].u=r[i].v,r[m+i].v=r[i].u,r[m+i].w=r[i].w;
	}
	for (int i=0;i<k;i++){
		cin >> c[i].co;
		for (int j=1;j<=n;j++) cin >> c[i].a[j];
	}
	bool flag=true;
	for (int i=0;i<k;i++) flag=(flag&&c[i].co==0);
	if(flag){
		int o,q=m*2,mi,ma,fi=1;
		for (int i=0;i<k;i++){
			for (o=1;o<=n;o++) if(c[i].a[o]==0) break;
			for (int j=1;j<=n;j++){
				if(o!=j){
					r[q].u=o,r[q].v=j,r[q].w=c[i].a[j],q++;
					r[q].v=o,r[q].u=j,r[q].w=c[i].a[j],q++;
				}
			}
		}
		sort(r,r+q,cmp);
		for (int i=0;i<q;i++){
			if(f[r[i].u]==0||f[r[i].v]==0){
				if(f[r[i].u]==0&&f[r[i].v]==0) ans+=r[i].w,f[r[i].u]=fi,f[r[i].v]=fi,fi++;
				else ans+=r[i].w,f[r[i].u]=max(f[r[i].u],f[r[i].v]),f[r[i].v]=max(f[r[i].u],f[r[i].v]);
			}else if(f[r[i].u]!=f[r[i].v]){
				mi=min(f[r[i].u],f[r[i].v]),ma=max(f[r[i].u],f[r[i].v]);
				for (int j=1;j<=n;j++) if(f[j]==mi) f[j]=ma;
				ans+=r[i].w;
			}
		}
	}else{
		int p=1;
		ans=LONG_LONG_MAX;
		for (int i=0;i<k;i++) p*=2;
		for (int i=0;i<p;i++) ans=min(ans,fin(i));
	}
	cout << ans;
	return 0;
}
