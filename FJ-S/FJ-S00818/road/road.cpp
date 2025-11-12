#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,ans=1e18,cnt,ff,d[10050],s[10050],ss[10050],f[10050],fa[10050][2050];
struct node{long long u,v,w,id;}a[1000005];
bool cmp(node a,node b){return a.w<b.w;}
long long find(long long x,long long op){
	if(fa[x][op]!=x)fa[x][op]=find(fa[x][op],op);
	return fa[x][op];
}
long long read(long long s=0,bool f=0,char c=0){
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?-s:s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),cnt=m=read(),k=read();
	for(int i=1;i<=m;i++)a[i].u=read(),a[i].v=read(),a[i].w=read(),a[i].id=k;
	for(int i=0;i<k;i++){
		d[i]=read();
		for(int j=1;j<=n;j++)cnt++,a[cnt].u=n+i+1,a[cnt].v=j,a[cnt].id=i,a[cnt].w=read();
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=0;i<(1<<k);i++)
	    for(int j=0;j<k;j++)
	        if(i&(1<<j))
	            s[i]+=d[j],ss[i]++;
	for(int i=1;i<=n+k;i++)
	    for(int j=0;j<(1<<k);j++)
	        fa[i][j]=i;
	for(int i=1;i<=cnt&&ff<(1<<k);i++)
		for(int j=0;j<(1<<k);j++)
			if((a[i].id==k||(j&(1<<a[i].id)))&&f[j]<n+s[j]-1){
				x=find(a[i].u,j),y=find(a[i].v,j);
				if(x!=y){
				    fa[x][j]=y,s[j]+=a[i].w,f[j]++;
				    if(f[j]==n+s[j]-1)ff++;
				}
			}
	for(int i=0;i<(1<<k);i++)ans=min(ans,s[i]);
	cout<<ans;
	return 0;
}

