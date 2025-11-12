#include <bits/stdc++.h>
using namespace std;
struct road{
	long long u,v,w;
}s[5000005];
bool cmp(road a,road b){
	return a.w<b.w;
}
long long n,m,k,t,a,b,an=0,c[15][5000005],ans=0;
int f[5000005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool chs[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]); 
		}
	}
	sort(s,s+m,cmp);
	for(int i=0;i<n;i++){
		f[i]=i;
	}
	for(int i=0;i<m;i++){
		a=s[i].u,b=s[i].v,t=s[i].w;
		if(find(a)!=find(b)){
			ans+=t;
			f[find(a)]=find(b);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
