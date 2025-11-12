#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10,K=11;
int n,m,k,siz[1020][1020],fa[N+K],tot,c[K],a[K][N],ld[N+K],len;
bool in[N];
ll ans=1e18,now;
struct road{
	int x,y,w;
}ro[M*3],rp[M];
struct Minn{
	int mi,ip;
}minn[1020][1020];
bool cmp(road x,road y){return x.w<y.w;}
bool cmp1(Minn x,Minn y){return x.mi<y.mi;}
ll ask(ll x){return fa[x]==x?x:fa[x]=ask(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ro[i].x>>ro[i].y>>ro[i].w;
		rp[i].x=ro[i].x,rp[i].y=ro[i].y,rp[i].w=ro[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		sort(ro+1,ro+m+1,cmp);
		ans=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int p=ask(ro[i].x),q=ask(ro[i].y);
			if(p!=q){
				fa[p]=q;
				tot++;
				ans=ans+ro[i].w;
				if(tot==n-1) break;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	int num=0;
	if(n<=1000&&m>100000){
		memset(siz,0x3f,sizeof(siz));
		for(int i=1;i<=m;i++) siz[ro[i].x][ro[i].y]=siz[ro[i].y][ro[i].x]=min(siz[ro[i].x][ro[i].y],ro[i].w);
		for(int r=0;r<(1<<k);r++){
			now=0;
			num=0;
			for(int i=1;i<=k;i++){
				if(r&(1<<(i-1))){
					num++;
					now=now+c[i];
					for(int j=1;j<=n;j++) siz[num+n][j]=siz[j][num+n]=a[i][j];
				}
			}
			for(int i=1;i<=n+num;i++) ld[i]=0;
			for(int i=1;i<=num+n;i++){
				for(int j=1;j<=num+n;j++){
					if(i!=j) minn[i][++ld[i]].mi=siz[i][j],minn[i][ld[i]].ip=j;
				}
				sort(minn[i]+1,minn[i]+n+num,cmp1);
			}
			for(int i=1;i<=n+num;i++) ld[i]=1,in[i]=0;
			in[1]=1;
			int minx,minp;
			n=n+num;
			for(int i=1;i<n;i++){
				minp=1e9+10;
				for(int j=1;j<=n;j++){
					if(in[j]&&ld[i]<=n+num&&minn[j][ld[j]].mi<minp) minp=minn[j][ld[j]].mi,minx=j;
				}
//				cout<<minx<<" "<<minp<<"\n";
				for(int j=1;j<=n;j++){
					if(siz[minx][j]==minp){
						in[j]=1;
						now=now+minp;
						ld[minx]++;
					}
				}
				for(int j=1;j<=n;j++){
					while(ld[j]<=n+num&&in[minn[j][ld[j]].ip]) ld[j]++;
				}
			}
			ans=min(ans,now);
			n=n-num;
//			cout<<now<<"\n";
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(n>1e3){
		int xx;
		len=m;
		for(int i=1;i<=m;i++){
			int mp=1e9+10;
			for(int j=1;j<=k;j++){
				if(ro[i].w>a[j][ro[i].x]+a[j][ro[i].y]){
					if(mp>a[j][ro[i].x]+a[j][ro[i].y]){
						mp=a[j][ro[i].x]+a[j][ro[i].y];
						xx=j;
					}
				}
			}
			xx=xx+n;
			if(mp==1e9+10) continue;
			else{
				ro[++len].x=xx,ro[len].y=ro[i].x,ro[len].w=a[xx][ro[i].x];
				ro[++len].x=xx,ro[len].y=ro[i].y,ro[len].w=a[xx][ro[i].y];
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					ro[++len].x=i+n,ro[len].y=j,ro[i].w=0;
					break;
				}
			}
		}
		sort(ro+1,ro+len+1,cmp);
		ans=0;
		n=n+k;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=len;i++){
			int p=ask(ro[i].x),q=ask(ro[i].y);
			if(p!=q){
				fa[p]=q;
				tot++;
				ans=ans+ro[i].w;
				if(tot==n-1) break;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	int p,q;
	for(int r=0;r<(1<<k);r++){
		now=0,num=0,len=m;
		for(int i=1;i<=m;i++) ro[i].x=rp[i].x,ro[i].y=rp[i].y,ro[i].w=rp[i].w;
		for(int i=1;i<=k;i++){
			if(r&(1<<(i-1))){
				num++;
				now=now+c[i];
				for(int j=1;j<=n;j++){
					ro[++len].x=num+n,ro[len].y=j,ro[len].w=a[i][j];
				}
			}
		}
		tot=0;
		sort(ro+1,ro+len+1,cmp);
		for(int i=1;i<=num+n;i++) fa[i]=i;
		for(int i=1;i<=len;i++){
			p=ask(ro[i].x),q=ask(ro[i].y);
			if(p!=q){
				fa[p]=q;
				now=now+ro[i].w;
				tot++;
				if(tot==n+num-1) break;
			}
		}
		ans=min(ans,now);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
