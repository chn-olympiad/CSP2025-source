#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10015];
int tot;
struct node{
	int x,y,v;
}a[1000002],b[10001],c[110001];
bool cmp(node p1,node p2){
	return p1.v<p2.v;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
int cnt,mx;
long long ans,ask;
bool flag[20];
int kk[11][10001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].v;		
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>kk[i][j];
		}
	}
	stable_sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int gx=get(a[i].x);
		int gy=get(a[i].y);
		if(gx!=gy){
			mx=a[i].v;
			ask+=a[i].v;
			cnt++;
			b[cnt]=a[i];
			fa[gx]=gy;
		}
		if(cnt==n-1)break;
	}
	for(int ii=1;ii<(1<<k);ii++){
		tot=n-1;
		for(int i=1;i<n;i++){
			c[i]=b[i];
		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		ans=0;
		int p=0;
		for(int j=1;j<=k;j++){
			flag[j]=(ii&(1<<j-1));
			if(flag[j]==1){
				ans+=kk[j][0];
				p++;
				for(int i=1;i<=n;i++){
					if(kk[j][i]<mx){
						c[++tot]={n+j,i,kk[j][i]};
					}
				}
			}
		}
		if(ans>ask)continue;
		stable_sort(c+1,c+tot+1,cmp);
		cnt=0;
		for(int i=1;i<=tot;i++){
			int gx=get(c[i].x);
			int gy=get(c[i].y);
			if(gx!=gy){
				fa[gx]=gy;
				ans+=c[i].v;
				cnt++;
				if(ans>=ask||cnt==n-1+p)break;
			}
		}
		ask=min(ask,ans);
	}
	cout<<ask;
	return 0;
}

