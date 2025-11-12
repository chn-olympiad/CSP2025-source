#include<bits/stdc++.h>
using namespace std;
#define FOR_R(i,a,b)	for(int i=a;i<=b;i++)
long long n,m,k,a[15][10010],cnt,f[10010],ans,tot;
struct P{
	long long u,v,w;
}e[10000000];
bool cmp(P x,P y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x)	return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	FOR_R(i,1,m)	{
		long long x,y,z;
		cin>>x>>y>>z;
		e[++cnt]={x,y,z};
	}
	FOR_R(i,1,k)	FOR_R(j,0,n)	cin>>a[i][j];
	FOR_R(i,1,n)	FOR_R(j,i+1,n)	{
		long long mn=0x3f3f3f3f;
		FOR_R(l,1,k)	mn=min(mn,a[l][i]+a[l][j]+a[l][0]);
		e[++cnt]={i,j,mn};
	}
	sort(e+1,e+cnt+1,cmp);
	FOR_R(i,1,n)	f[i]=i;
	FOR_R(i,1,cnt){
		int x=find(e[i].v),y=find(e[i].u);
		if(x!=y){
			tot++;ans+=e[i].w;
			f[x]=y;
		}
		if(tot==n-1)	break;
	}
	cout<<ans;
	return 0;
} 
