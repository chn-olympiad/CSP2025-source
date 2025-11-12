#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100001],ff[11][100001],ko[11],jo[11],co[11][100001],ky[11],l,x,y,z,sum,mx,my;
struct fk {
	int x,y,z;
} a[1000001];
bool cmp(fk a,fk b) {
	return a.z<b.z;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k<=0) {
		for(int i=1; i<=m; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1; i<=m && l<n; i++) {
			x=a[i].x;
			y=a[i].y;
			z=a[i].z;
			if(f[x]==1 && f[y]==1) continue;
			if(++f[x]==1) l++;
			if(++f[y]==1) l++;
			f[x]=1;
			f[y]=1;
			sum+=z;
		}
		cout<<sum;
	} else {
		for(int i=1; i<=m; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1; i<=k; i++) {
			cin>>ko[i];
			for(int j=1; j<=n; j++) {
				cin>>co[i][j];
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1; i<=m && l<n; i++) {
			x=a[i].x;
			y=a[i].y;
			z=a[i].z;
			if(f[x]==1 && f[y]==1) continue;
			mx=z;
			for(int j=1; j<=k; j++) {
				jo[j]+=z;
				if(ff[j][x]==0) ko[j]+=co[j][x],ff[j][x]=1,my=co[j][x];
				if(ff[j][y]==0) ko[j]+=co[j][y],ff[j][y]=1,my+=co[j][x];
				if(ky[j]==1) {
					mx=min(mx,my);
				}
				if(ky[j]==0 && ko[j]<=jo[j]) {
					ky[j]=1;
					sum=sum-jo[j]+ko[j];
				}
			}
			if(++f[x]==1) l++;
			if(++f[y]==1) l++;
			f[x]=1;
			f[y]=1;
			sum+=my;
		}
		cout<<sum;
	}
	return 0;
}
