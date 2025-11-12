#include<bits/stdc++.h>
using namespace std;
long long F(){//Fastwrite
	long long kk=0;
	char c;
	c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9'){
		kk=kk*10+c-48;
		c=getchar();
	}
	return kk;
}
long long n,m,k,ans;
struct sj{
	long long u,v,w;
}e[1000005];
long long a[15][10005];
int fa[10005];
bool cmp(sj aa,sj bb){
	return aa.w<bb.w;
}
int find(int aaa){
	if(fa[aaa]!=aaa) fa[aaa]=find(fa[aaa]);
	return aaa;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=F(),m=F(),k=F();
	for(int i=1;i<=m;i++){
		e[i].u=F(),e[i].v=F(),e[i].w=F();
	}
	for(int i=1;i<=k;i++){
		a[k][0]=F();
		for(int j=1;j<=n;j++){
			a[k][j]=F();
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
