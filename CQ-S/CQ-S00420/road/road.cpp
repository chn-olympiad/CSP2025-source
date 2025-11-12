#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct{
	int t,mx;
	bool tag,vis;
}a[N<<1];
struct{
	int to,ne,w;
}b[M<<2];
struct DD{
	int id,w;
	inline bool operator<(const DD z) const {return w<z.w;}
}d[N];
int c[15];
struct que{
	int x,w;
	inline bool operator<(const que z) const {return w<z.w;}
}q[M<<2];
int n,k;
void pop(int& tp){
	q[1]=q[tp--];
	for(int i=1,j=2;j<=tp;swap(q[i],q[j]),i=j,j<<=1){
		if((j|1)<=tp&&q[j|1]<q[j]) j|=1;
		if(q[i]<q[j]) return;
	}
}
void push(const int x,int& tp){
	q[++tp]={x,a[x].mx};
	for(int i=tp;i>1;swap(q[i],q[i>>1]),i>>=1)
		if(q[i>>1]<q[i]) return;
}
long long solve(long long ans,int tp=1){
	for(int i=1;i<=n+k;i++) a[i].mx=1e9,a[i].vis=0;
	q[1]={1,0},a[1].mx=0;
	while(tp){
		const int x=q[1].x;
		pop(tp);
		if(a[x].vis) continue;
		ans+=a[x].mx,a[x].vis=1;
		for(int i=a[x].t,y;i;i=b[i].ne) if(a[y=b[i].to].tag&&a[y].mx>b[i].w)
			a[y].mx=b[i].w,push(y,tp);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,cnt=0;
	long long ans=1e18;
	cin>>n>>m>>k;
	for(int x,y,w;m--;) cin>>x>>y>>w,
		b[++cnt]={y,a[x].t,w},a[x].t=cnt,b[++cnt]={x,a[y].t,w},a[y].t=k;
	for(int j=1,now=n;j<=k;j++){
		cin>>c[j],now++;
		for(int i=1,w;i<=n;i++) cin>>w,
			b[++cnt]={i,a[now].t,w},a[now].t=cnt,b[++cnt]={now,a[i].t,w},a[i].t=cnt;
	}
	for(int i=1;i<=n;i++) a[i].tag=1;
	for(int i=0;i<(1<<k);i++){
		long long s=0;
		for(int j=1;j<=k;j++) a[j+n].tag=((i>>(j-1))&1),s+=c[j]*(a[j+n].tag);
		ans=min(ans,solve(s));
	}
	cout<<ans;
}
