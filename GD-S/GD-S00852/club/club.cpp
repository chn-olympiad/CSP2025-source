#include<bits/stdc++.h>
using namespace std;
struct node{
	int maxx,minn,id1,id2;
}f[100005];
int n,ans,cnt[4];
bool cmp(node x,node y){
	return x.maxx-x.minn>y.maxx-y.minn;
}
void work(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c,g[4];
		scanf("%d%d%d",&a,&b,&c);
		g[1]=a,g[2]=b,g[3]=c;
		sort(g+1,g+3+1);
		f[i].maxx=g[3],f[i].minn=g[2];
		if(f[i].maxx==a) f[i].id1=1;
		else if(f[i].maxx==b) f[i].id1=2;
		else if(f[i].maxx==c) f[i].id1=3;
		if(f[i].minn==c) f[i].id2=3;
		else if(f[i].minn==b) f[i].id2=2;
		else if(f[i].minn==a) f[i].id2=1;
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=3;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		if(cnt[f[i].id1]<n/2) cnt[f[i].id1]++,ans+=f[i].maxx;
		else cnt[f[i].id2]++,ans+=f[i].minn;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) work();
	return 0;
}
