#include<bits/stdc++.h>
using namespace std;
long long n,n2,m,k,fa[10005],vis[10012],pp[12];
struct nd{
	long long u,v,w;
}a[10000005];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
long long find(long long x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	n2=n;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		long long x,p[10005],idx;
		cin>>x;
		if(x==0){
			for(int j=1;j<=n;j++){
				cin>>p[j];
				if(p[j]==0)idx=j;
			}
			for(int j=1;j<=n;j++){
				if(j==idx)continue;
				m++;
				a[m].u=idx,a[m].v=j,a[m].w=p[j];
			}
		}else if(n<=1000){
			pp[i]=x;
			n2++;
			for(int j=1;j<=n;j++)
				cin>>p[j];
			for(int j=1;j<=n;j++){
				m++;
				a[m].u=n2,a[m].v=j,a[m].w=p[j];
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)vis[i]=1;
	for(int i=n+1;i<=n2;i++)vis[i]=0;
	long long t=0,ans=0;
	//for(int i=1;i<=m;i++)cout<<a[i].u<<a[i].v<<a[i].w<<endl;
	for(int i=1;i<=m;i++){
		int x=a[i].u,y=a[i].v;
		int x_=find(x),y_=find(y);
		if(x_!=y_){
			fa[x_]=y_;
			if(vis[x_]&&vis[y_])t++;
			else vis[x_]=1,vis[y_]=1;
			if(x>n)ans+=(a[i].w+pp[x-n]),pp[x-n]=0;
			else if(y>n)ans+=(a[i].w+pp[y-n]),pp[y-n]=0;
			else ans+=a[i].w;
		}
		if(t==n-1){
			cout<<ans;
			return 0;
		}
	}
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
