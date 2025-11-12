#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
const int N=1e6+10;
inline int max(int a,int b){return a>b?a:b; }
inline int min(int a,int b){return a<b?a:b; }
bool vis[N];
int n,m,ans,cnt,k;
int w[N];
struct node{
	int x,y,z;
}a[N],f[N],a1[N],a2[N],a3[N],a4[N],a5[N];
bool cmp(node xx,node yy){
	return xx.z<yy.z;
}
int act(node A[],int limit){
	int res=0,cnt=0;
	sort(A+1,A+limit+1,cmp);
	for(reg int i=1;i<=m+n*k;i++){
		if(cnt==n)break;
		int u=A[i].x,v=A[i].y;
		if(!vis[u]){
			res+=A[i].z; 
			vis[u]=1;
			if(!vis[v]){
				vis[v]=1;
				if(v<=n)cnt++;
			}
			if(u<=n)cnt++;
		}
		else if(!vis[v]){
			res+=A[i].z; 
			vis[v]=1;
			if(!vis[u]){
				vis[u]=1;
				if(u<=n)cnt++;
			}
			if(v<=n)cnt++;
		}
		if(res>=ans)return -1;
	}
	return res;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(reg int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		f[i].x=a[i].x,f[i].y=a[i].y,f[i].z=a[i].z;			
	}
	for(reg int i=1;i<=k;i++){
		scanf("%d",&w[n+i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[m+n*(i-1)+j].z);
			f[m+n*(i-1)+j].z=a[m+n*(i-1)+j].z;
			f[m+n*(i-1)+j].x=a[m+n*(i-1)+j].x=n+i;
			f[m+n*(i-1)+j].y=a[m+n*(i-1)+j].y=j;
		}
	}
	sort(a+1,a+m+n*k+1,cmp);
	for(reg int i=1;i<=m+n*k;i++){
		if(cnt==n)break;
		int u=a[i].x,v=a[i].y;
		if(!vis[u]){
			ans+=a[i].z; 
			vis[u]=1;
			if(!vis[v]){
				vis[v]=1;
				if(v<=n)cnt++;
			}
			if(u<=n)cnt++;
		}
		else if(!vis[v]){
			ans+=a[i].z; 
			vis[v]=1;
			if(!vis[u]){
				vis[u]=1;
				if(u<=n)cnt++;
			}
			if(v<=n)cnt++;
		}
	}
	if(!k){
		printf("%d\n",ans);
		return 0;
	}
	for(reg int i=1;i<=n+k;i++){
		if(vis[i]&&i>=n+1)ans+=w[i];
		vis[i]=0;
	}
	for(reg int i=1;i<=m;i++)
		a1[i]=a2[i]=a3[i]=a4[i]=a5[i]=f[i];
	for(reg int i=1;i<=n;i++){
		a1[m+i]=f[m+i];
		a2[m+i]=f[m+n*1+i];
		a3[m+i]=f[m+n*2+i];
		a4[m+i]=f[m+n*3+i];
		a5[m+i]=f[m+n*4+i];
	}
	int ttt=act(a1,m+n);
	if(ttt!=-1&&ttt!=0)ans=min(ans,ttt+w[n+1]);
	ttt=act(a2,m+n);
	if(ttt!=-1&&ttt!=0)ans=min(ans,ttt+w[n+2]);
	ttt=act(a3,m+n);
	if(ttt!=-1&&ttt!=0)ans=min(ans,ttt+w[n+3]);
	ttt=act(a4,m+n);
	if(ttt!=-1&&ttt!=0)ans=min(ans,ttt+w[n+4]);
	ttt=act(a5,m+n);
	if(ttt!=-1&&ttt!=0)ans=min(ans,ttt+w[n+5]);
	printf("%d\n",ans);
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4


