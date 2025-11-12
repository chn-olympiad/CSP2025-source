#include<bits/stdc++.h>
using namespace std;
int aaaaa;
struct H{long long x,y,z,no;}c[2000007],d[2000007];
bool cmp(H x,H y){return x.z<y.z;}
long long tn,n,m,k,l,T,ans,s1,s2,s3,ss,sn,b[1000007],js,f[1000007],cn,anz,w[1000007];
int bbbbb;
int fg(int x){return f[x]==x?x:f[x]=fg(f[x]);}
void M(int x,int y,long long z,int ty,int no){
	int fx=fg(x),fy=fg(y);
	if(fx!=fy){
		f[fx]=fy;
		if(ty)d[++cn]=c[no];
		else ans+=z;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	//cerr<<(double)(&aaaaa-&bbbbb)/6e7*256<<'\n';
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	anz=1e18;
	cin>>n>>m>>l;tn=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>c[i].x>>c[i].y>>c[i].z,c[i].no=0;
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m;i++)M(c[i].x,c[i].y,c[i].z,1,i);
	for(int i=1;i<=l;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			d[++cn].x=n+i,d[cn].y=j;
			cin>>d[cn].z;
			d[cn].no=i;
		}
	}
	sort(d+1,d+cn+1,cmp);
	for(int i=0;i<=(1<<l)-1;i++){
		ans=0;
		for(int j=1;j<=n;j++)f[j]=j;
		for(int j=1;j<=l;j++)if((i>>(j-1))&1)f[n+j]=n+j,ans+=w[j];
		for(int j=1;j<=cn;j++){
			if(!d[j].no||((i>>(d[j].no-1))&1)){
				M(d[j].x,d[j].y,d[j].z,0,0);
				//if(i==1)cout<<i<<' '<<ans<<'\n';
			}
		}
		anz=min(anz,ans);
		//cout<<i<<' '<<ans<<'\n';
	}
	cout<<anz;
}
