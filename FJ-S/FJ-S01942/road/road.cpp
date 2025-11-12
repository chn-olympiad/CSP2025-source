#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
#define pb push_back
//#define int ll
using namespace std;
inline void dd(int &xx){
	xx=0;
	int ff=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	xx*=ff;
}
const int N=4e4+5,M=2e6+5,K=15;
int n,m,c[K],k,nw[K],f[N],siz[N],num=0;
ll ans=0;
priority_queue<pii> q;
vector<pii> G[K];
struct sb{
	int x,y,z;
}bian[M],a[N];
bool cmp(sb aa,sb bb){
	return aa.z<bb.z;
}
int fid(int x){
	return x==f[x]?x:f[x]=fid(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	dd(n),dd(m),dd(k);
	for(int i=1;i<=m;++i) dd(bian[i].x),dd(bian[i].y),dd(bian[i].z);
	for(int i=1;i<=n;++i) f[i]=i,siz[i]=1;
	sort(bian+1,bian+1+m,cmp);
	ll sum=0;int uuu=0;
	for(int i=1;i<=m;++i){
		int x=bian[i].x,y=bian[i].y,z=bian[i].z;
		int fx=fid(x),fy=fid(y);
		a[++num]=bian[i];
		if(fx==fy) continue;
		sum+=z;
		if(siz[fx]>siz[fy]) swap(fx,fy);
		f[fx]=fy;
		siz[fy]+=siz[fx];
		++uuu;
		if(uuu==n-1) break;
	}
	ans=sum;
//	cout<<sum<<endl;
	for(int i=1;i<=k;++i){
		dd(c[i]);
		for(int j=1,x;j<=n;++j){
			dd(x);
			G[i].pb({x,j});
		}
		sort(G[i].begin(),G[i].end());
	}
//	cout<<"ksdlasdk"<<endl;
	int S=1<<k;
//	cout<<S<<endl;
	for(int i=1;i<S;++i){
		int yu=0;
		sum=0;
		for(int i=1;i<=n;++i) f[i]=i,siz[i]=1;
		while(q.size()) q.pop();
		for(int j=1;j<=k;++j){
			nw[j]=0;f[n+j]=n+j,siz[n+j]=1;
			if((i>>(j-1))&1){
				sum+=c[j];
				q.push({-G[j][nw[j]].X,j});
				++yu;
			}
		}
//		cout<<i<<endl;
//		cout<<f[5]<<endl;
//		cout<<fid(5)<<endl;
		int cnt=0,l=1;
		while(cnt<n+yu-1){
//			cout<<i<<" "<<cnt<<" "<<sum<<" "<<q.size()<<" "<<l<<endl;
			if(q.size()&&(l>num||-q.top().X<a[l].z)){
				int x=q.top().Y,y=G[x][nw[x]].Y,z=-q.top().X;
				q.pop();++nw[x];
				if(nw[x]<n) q.push({-G[x][nw[x]].X,x});
				x+=n;
				int fx=fid(x),fy=fid(y);
//				cout<<x<<"???"<<y<<" "<<fx<<" "<<fy<<endl;
				if(fx==fy) continue;
				++cnt;
				sum+=z;
				if(siz[fx]>siz[fy]) swap(fx,fy);
				f[fx]=f[fy];
				siz[fy]+=siz[fx];
			}else{
				int x=bian[l].x,y=bian[l].y,z=bian[l].z;
				int fx=fid(x),fy=fid(y);
				++l;
//				if(l>=n+1) return cout<<"cnm"<<endl,0; 
				if(fx==fy) continue;
				sum+=z,++cnt;
				if(siz[fx]>siz[fy]) swap(fx,fy);
				f[fx]=f[fy],siz[fy]+=siz[fx];
			}
		}
		ans=min(sum,ans);
	}
	printf("%lld\n",ans);
}
