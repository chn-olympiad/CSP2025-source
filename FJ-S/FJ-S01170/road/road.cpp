#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10010,M=10000010;
struct node{
	int x,y,z;
	bool operator <(const node &a)const{return z<a.z;}
}a[M],b[N];
int n,m,k,tot,fa[N],c[N],ed[15][N];
ll ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll askk(int nn,int mm,bool f){
	for(int i=1;i<=nn;i++) fa[i]=i;
	sort(a+1,a+mm+1);
	ll res=0,s=0;
	for(int i=1;i<=mm;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy) continue;
		fa[fx]=fy,res+=a[i].z;
		if(fx<=n&&fy<=n) s++;
		if(f) b[s]={a[i].x,a[i].y,a[i].z};
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//		if(s==n-1) break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	ans=askk(n,m,1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>ed[i][j];
	}
//	for(int i=1;i<(1<<k);i++){
	int i=(1<<k)-1;
	ll s=0;
	int tott=n-1,num=0;
	for(int jj=1;jj<n;jj++) a[jj]=b[jj];
	for(int xx=0;xx<k;xx++){
		int j=xx+1;
		if((i>>xx)&1){
			s+=c[j],num++;
			for(int ii=1;ii<=n;ii++) a[++tott]={n+j,ii,ed[j][ii]};
		}
	}
	ans=min(ans,s+askk(n+num,tott,0));
//	}
	cout<<ans;
	return 0;
}

