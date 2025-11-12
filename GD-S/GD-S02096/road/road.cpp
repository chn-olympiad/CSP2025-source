#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,m,k,cnt,ans,tot,f[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int x,y,z;
}e[N];
bool cmp(node a,node b){
	return a.z<b.z;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].x=read(),e[i].y=read(),e[i].z=read();
		cnt++;
	}
	for(int i=1,cst;i<=k;i++){
		cst=read();
		for(int j=0;j<n;j++){
			cnt++;
			e[cnt].z=read();
			e[cnt].x=i+m,e[cnt].y=j+1;
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			ans+=e[i].z;
			fa[x]=y;
			if(x<=n&&f[x]!=1) f[x]=1,tot++;
			if(y<=n&&f[y]!=1) f[y]=1,tot++;
		}
		if(tot>=n) break;
	} 
	cout<<ans;
	return 0;
}
