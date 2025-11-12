#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,w[15],len;
struct nd{
	int x,y,w;
}a[1000005],b[110005];
int f[10015],sz[10015];
int find(int c){
	return f[c]==c?c:f[c]=find(f[c]);
}
void merge(int x,int y){
	if(sz[x]>sz[y])f[y]=x,sz[x]+=sz[y];
	else f[x]=y,sz[y]+=sz[x];
}
bool cmp(nd x,nd y){
	return x.w<y.w;
}
ll cnt,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i=0;i<k;++i){
		cin>>w[i];
		for(int j=1,x;j<=n;++j){
			x=i*n+j;
			b[x].x=i+n+1,b[x].y=j,cin>>b[x].w;
		}
	}
	len=n*k;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(int i=1,x,y;i<=m;++i){
		x=find(a[i].x),y=find(a[i].y);
		if(x==y)continue;
		b[++len]=a[i],merge(x,y);
	}
	sort(b+1,b+1+len,cmp);
	ans=1e18;
	for(int i=0;i<(1<<k);++i){
		cnt=0;
		for(int i=1;i<=n+k;++i)f[i]=i,sz[i]=1;
		for(int j=0;j<k;++j)
		if(i&(1<<j))cnt+=w[j];
		for(int j=1,x,y;j<=len;++j){
			if(b[j].x>n&&!(i&(1<<(b[j].x-n-1))))continue;
			x=find(b[j].x),y=find(b[j].y);
			if(x==y)continue;
			cnt+=b[j].w,merge(x,y);
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}/*
预先对两部分边分别排序 
*/
