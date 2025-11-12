#include<bits/stdc++.h>
using namespace std;
long long ans,now;
int n,m,k,t1,t2,t3,rx,ry,tot,len,mm,p1,p2,cl,c[500010],siz[500010],fa[500010],fn[500010],book[500010];
struct node{
	long long w;
	int u,v,op,bel,pri;
}a[1100010],b[1100010],cc[1100010];
struct node1{
	long long val;
	int num;
}cw[12][20010];
bool cmp1(node1 t1,node1 t2){
	return t1.val<t2.val;
}
bool cmp2(node t1,node t2){
	return t1.w<t2.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node t1,node t2){
	if(t1.bel!=t2.bel) return t1.w<t2.w;
	if(t1.pri!=t2.pri) return t1.pri>t2.pri;
	return t1.w<t2.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=(i<=n?1:0);
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w,a[i].op=true,a[i].bel=0,a[i].pri=1e9;
	sort(a+1,a+1+m,cmp2);
	if(k<=5){
		for(int i=0;i<k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>cw[i][j].val,cw[i][j].num=j;
		}
//		return 0;
		ans=1e15;
		for(int i=0;i<(1<<k);i++){
			
			now=0;mm=0;tot=0;len=0;
			for(int j=1;j<=n+k;j++) fa[j]=j;
			mm=0;
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					len++;
					now+=c[j];
					for(int l=1;l<=n;l++){
						mm++;
						b[mm].u=j+1+n;
						b[mm].v=cw[j][l].num;
						b[mm].w=cw[j][l].val;
					}
				}
			}
			sort(b+1,b+1+mm,cmp2);
			p1=1,p2=1,cl=0;
			while(p1<=m&&p2<=mm){
				if(a[p1].w<=b[p2].w){
					cc[++cl]=a[p1];
					p1++;
				}
				else{
					cc[++cl]=b[p2];
					p2++;
				}
			}
			while(p1<=m) cc[++cl]=a[p1++];
			while(p2<=mm) cc[++cl]=b[p2++];
//			cout<<mm<<"\n";
			for(int j=1;j<=cl;j++){
				rx=find(cc[j].u);
				ry=find(cc[j].v);
				if(rx==ry) continue;
//				cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<"\n";
				now+=1ll*cc[j].w;
				tot++;
				fa[ry]=rx;
				if(tot==n+len-1) break;
			}
			ans=min(ans,now);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>cw[i][j].val,cw[i][j].num=j;
		
		sort(cw[i]+1,cw[i]+1+n,cmp1);
		m++;
		a[m].bel=i+n;a[m].pri=1e9;
		a[m].u=cw[i][1].num;
		a[m].op=false;
		
		a[m].v=i+n;
		fn[i+n]=a[m].w=cw[i][1].val+c[i];
		
		for(int j=2;j<=n;j++){
			m++;
			a[m].bel=i+n;a[m].pri=0;
			a[m].u=cw[i][j].num;
			a[m].v=i+n;
			a[m].w=cw[i][j].val;
			a[m].op=true;
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		rx=find(a[i].u);
		ry=find(a[i].v);
		if(rx==ry) continue;
		ans+=1ll*a[i].w;
		if(siz[rx]&&siz[ry]) tot++;
		fa[ry]=rx;
		siz[rx]+=siz[ry];
		siz[ry]=0;
		if(tot==n-1) break;
	}
//	for(int i=1;i<=k;i++) if(siz[find(n+i)]<=1) ans-=fn[n+i];
	cout<<ans;
	return 0;
} 
