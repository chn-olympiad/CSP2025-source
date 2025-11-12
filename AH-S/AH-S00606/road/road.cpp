#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int n,m,k,c[15],a[15][N];
int b[N],cnt;
long long ans;
bool flag[15][N];
bool flag1[15];
struct road{
	int u,v,w;
}r[M];
struct cou{
	int w,to;
}aa[15][N];
bool cmp(road x,road y){
	return x.w>y.w;
}
bool cmp2(cou x,cou y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		b[r[i].u]++;
		b[r[i].v]++;
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			aa[i][j].w=a[i][j];
			aa[i][j].to=j;
		}
		sort(aa[i]+1,aa[i]+n+1,cmp2);
	}
	for(int i=1;i<=m;i++){
		int x=r[i].u,y=r[i].v,z=r[i].w;
		if(b[x]>1&&b[y]>1){
			cnt++;
			b[x]--;
			b[y]--;
			continue;
		}
		else{
			int ne,mind=1,other;
			long long minn=LONG_LONG_MAX;
			if(b[x]==1)ne=x;
			else ne=y;
			for(int j=1;j<=k;j++){
				long long co=a[j][ne];
				int oth;
				if(flag[j][ne])co-=a[j][ne];
				int now=1;
				while((aa[j][now].to==ne||b[aa[j][now].to]==0)&&now<=n){
					now++;
				}
				if(now>n){
					continue;
				}
				oth=aa[j][now].to;
				co+=aa[j][now].w;
				co+=c[j];
				if(flag[j][oth]){
					co-=aa[j][now].w;
				}
				if(flag1[j]){
					co-=c[j];
				}
				if(co<minn){
					minn=co;
					mind=j;
					other=oth;
				}
			}
			if(minn<z){
				flag1[mind]=1;
				flag[mind][ne]=1;
				flag[mind][other]=1;
				b[x]--;
				b[y]--;
				ans+=minn;
			}
			else{
				ans+=z;
			}
		}
	}
	cout<<ans;
	return 0;
}
