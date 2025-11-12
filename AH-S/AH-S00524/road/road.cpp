#include<bits/stdc++.h>
using namespace std;
struct cy{
	int u,v,w;
}a[1100005];
int n,m,k,p,dis[2005];
int fa[1100005],m2,t[1100][1100];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int hb(int x,int b){
	fa[find(x)]=find(b);
	return 0;
}
bool cmp(cy x,cy y){
	return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k; int b,c,d;
    for(int i=1;i<=m;i++){
		scanf("%d%d%d",&b,&c,&d);
		a[++m2]=(cy){b,c,d};
	}
    for(int i=1;i<=k;i++){
		scanf("%d",&b);
        for(int j=1;j<=n;j++){
		    scanf("%d",&c);
			if(b!=0);
			//	p=1;
			else
		        a[++m2]=(cy){n+i,j,c};
		}
	}
	if(p==0){
		long long ans=0;
        for(int i=1;i<=n+k;i++)
            fa[i]=i;
		sort(a+1,a+m2+1,cmp);
		for(int i=1;i<=m2;i++)
		    if( find(a[i].u)!=find(a[i].v) ){
				hb(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		cout<<ans;
	}
    fclose(stdin); fclose(stdout);
    return 0;
}
