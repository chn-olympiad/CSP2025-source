#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,cnt,nw,ed;
int f[20005],c[20];
int vis[20];
int find(int x){
	return f[x]==x?x:(f[x]=find(f[x]));
}
struct qwe{
	int x,y,z;
}a[1000005],b[200005];
bool cmp(qwe a,qwe b){
	return a.z<b.z;
}
ll ans,res;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		int fx=find(a[i].x);
		int fy=find(a[i].y);
		if(fx==fy) continue;
		f[fx]=fy;
		b[++cnt]=a[i];
		ans+=a[i].z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			b[++cnt].x=j;
			b[cnt].y=i+n;
			scanf("%d",&b[cnt].z);
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<1<<k;i++){
		res=0,nw=0,ed=0;
		for(int j=0;j<k;j++){
			vis[j+1]=0;
			if(i&1<<j){
				vis[j+1]=1;
				res+=c[j+1];
				ed++;
			}
		}
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=cnt;j++){
			if(res>ans) break;
			if(nw==n+ed-1) break;
			if(b[j].y>n&&vis[b[j].y-n]==0) continue;
			int fx=find(b[j].x);
			int fy=find(b[j].y);
			if(fx==fy) continue;
			f[fx]=fy;
			res+=b[j].z;
			nw++;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
